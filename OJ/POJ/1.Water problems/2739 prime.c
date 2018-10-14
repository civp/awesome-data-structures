#include <stdio.h>
#define N 11000
int isprime[N];
int prime[N];
int cnts = 0;

void prime_sieve(int prime[]){
	for(int i = 2; i < N; i++)
		isprime[i] = 1;
	isprime[0] = isprime[1] = 0;
	for(int i = 2; i < N; i++)
		if(isprime[i]){
			prime[cnts++] = i;
			for(int j = i * i; j < N; j += i)
				isprime[j] = 0;
		}
}

int main(){
	prime_sieve(prime);
	int n, cnt;

	scanf("%d", &n);
	while(n != 0){
		cnt = 0;
		for(int i = 0; prime[i] <= n; i++){
			int sum = prime[i];
			int j = 1;
			while(sum < n){
				sum += prime[i + j];
				j++;
			}
			if(sum == n)
				cnt++;
		}
		printf("%d\n", cnt);
		scanf("%d", &n);
	}
}