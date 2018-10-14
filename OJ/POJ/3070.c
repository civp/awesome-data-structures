#include <stdio.h>

const int mod = 10000;

int* multiply_matrix(long a[2][2], long b[2][2])
{
	long c11 = a[0][0] * b[0][0] + a[0][1] * b[1][0];
	long c12 = a[0][0] * b[0][1] + a[0][1] * b[1][1];
	long c21 = a[1][0] * b[0][0] + a[1][1] * b[1][0];
	long c22 = a[1][0] * b[0][1] + a[1][1] * b[1][1];
	long c[2][2] = {c11 % mod, c12 % mod, c21 % mod, c22 % mod};
	return c;
}

int* power_matrix(long mtx[2][2], int n)
{
//	if(n == 0){
//		int ret[2][2] = {1, 0, 1, 0};
//		return ret;
//	}
//	if(n == 1)
//		return mtx;
//	if(n % 2)
//		return multiply_matrix(multiply_matrix(power_matrix(mtx, n / 2), power_matrix(mtx, n / 2)), mtx);
//	else
//		return multiply_matrix(power_matrix(mtx, n / 2), power_matrix(mtx, n / 2));
	long E[2][2] = {1, 0, 1, 0};
	long* ret = E;
	long* tmp = mtx;
	while(n > 0){
		if(n & 1)
			ret = multiply_matrix(ret, mtx);
		tmp = multiplt_matrix(mtx, mtx);
		n >>= 1;	
	}
	return ret;
}

long fib(int n)
{
	long mtx[2][2] = {1, 1, 1, 0};
	int* ret = power_matrix(mtx, n);
	return *(ret + 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	while(n != -1){
		long output;
		output = fib(n);
		printf("%d\n", output % 10000);
		scanf("%d", &n);
	}
	return 0;
}