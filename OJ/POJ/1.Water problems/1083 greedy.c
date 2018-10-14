#include <stdio.h>
#define MAX 200

struct move{
	int s;
	int t;
};
typedef struct move mtab[MAX];
int cor[MAX];

void sort(mtab mt, int n){
	for(int i = 1; i < n; i++)
		for(int j = i; j > 0 && mt[j].s < mt[j - 1].s; j--){
			struct move tmp = mt[j];
			mt[j] = mt[j - 1];
			mt[j - 1] = tmp;
		}
}

int isdone(mtab mt, int n){
	int ret = 1;
	for(int i = 0; i < n; i++)
		if(mt[i].s)
			ret = 0;
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		mtab mt;
		int tmp1, tmp2;
		for(int i = 0; i < N; i++){
			scanf("%d", &tmp1);
			scanf("%d", &tmp2);
			mt[i].s = tmp1 < tmp2 ? tmp1 : tmp2;
			mt[i].t = tmp1 > tmp2 ? tmp1 : tmp2;
		}
		sort(mt, N);

		int cnt = 0;
		while(!isdone(mt, N)){
			for(int i = 0; i < MAX; i++)
				cor[i] = 0;//clear corridor
			for(int i = 0; i < N; i++){
				if(!mt[i].s)
					continue;
				int head = (mt[i].s - 1) / 2;
				int rear = (mt[i].t - 1) / 2;
				int sta = 1;
				for(int j = head; j <= rear; j++)
					if(cor[j]){
						sta = 0;
						break;
					}
				if(sta){
					for(int j = head; j <= rear; j++)
						cor[j] = 1;
					mt[i].s = 0;//if done, kill it.
				}
			}
			cnt++;
		}
		printf("%d\n", cnt * 10);
	}
}