/*
 * #12 Highly Divisible Triangular number
 * record d[n]: n -> #divisors, {n}: the set of all divisors of a
 * i-th triangular number n = i * (i + 1) / 2
 * divide n into two divisors a and b
 * d[n] = ord{n} = ord(union({a}, {b}, mul({a}, {b}))
 * where mul(s, t) is the set of multiples of elements in s and t
 * But it sucks, let's do BF
 * n has at most 2*sqrt(n) divisors
 * so start from 250^2
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TABLE_SIZE 200000000
int notPrime[TABLE_SIZE];
int primes[TABLE_SIZE];
int top;

void makePrimeTb()
{
	notPrime[0] = notPrime[1] = 1;
	for (int i = 2; i < TABLE_SIZE; ++i)
		if (!notPrime[i])
		{
			primes[top++] = i;
			for (int j = i * i; j < TABLE_SIZE; j += i)
				notPrime[i] = 1;
		}
}

int numOfDivisors(long long a)
{
	const int size = (int)sqrt(a) + 1;
	int ans = 1;
	for (int i = 0; i < size; ++i)
	{
		int exp = 0;
		while (a % primes[i] == 0)
		{
			exp += 1;
			a /= primes[i];
		}
		ans *= exp + 1;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	makePrimeTb();
	int d = 0, j = 2500, init = j * (j - 1) / 2, i;
	for (i = init; d <= 500; i += 2 * (j++ - 1))
	{
		d = numOfDivisors(i);
		if (d > 500)
			printf("%d\n", i);
	}
	return 0;
}