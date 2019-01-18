#include <stdio.h>
#define MAX 1000000
#define WID 3
int prime[MAX];
int isprime[MAX];
int count = 0;

void prime_sieve(int prime[]){
	for(int i = 2; i < MAX; i++)
		isprime[i] = 1;
	isprime[0] = isprime[1] = 0;
	for(int i = 2; i < MAX; i++)
		if(isprime[i]){
			prime[count++] = i;
			for(int j = i * 2; j < MAX; j += i)
				isprime[j] = 0;
		}
}

int main(){
	prime_sieve(prime);
	int dset[WID];
	int ans, cnt;

	for(int i = 0; i < WID; i++)
		scanf("%d", &dset[i]);
	while(dset[0]){
		cnt = 0;
		int a = dset[0];
		int d = dset[1];
		while(cnt != dset[2]){
			if(isprime[a])
				cnt++;
			a += d;
		}
		printf("%d\n", a - d);
		for(int i = 0; i < WID; i++)
			scanf("%d", &dset[i]);		
	}
}