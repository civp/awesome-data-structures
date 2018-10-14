#include <stdio.h>
#define MAX 1000000
int prime[MAX];
int isprime[MAX];
int cnt = 0;

void prime_sieve(int prime[]){
	for(int i = 2; i < MAX; i++)
		isprime[i] = 1;
	isprime[0] = isprime[1] = 0;
	for(int i = 2; i < MAX; i++)
		if(isprime[i]){
			prime[cnt++] = i;
			for(int j = i * 2; j < MAX; j += i)//when 1m, if squared, namely 1e3b, exceed 2.1b!
				isprime[j] = 0;
		}
}

int main(){
	prime_sieve(prime);
	int inp;
	scanf("%d", &inp);
	while(inp != 0){
		for(int i = 0; prime[i] < inp; i++){
			if(isprime[inp - prime[i]]){
				printf("%d = %d + %d\n", inp, prime[i], inp - prime[i]);
				break;
			}
		}
		scanf("%d", &inp);
	}
}