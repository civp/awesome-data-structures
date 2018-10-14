#include <stdio.h>
#include <math.h>
#define MAX 1000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
int T, cas = 1;
int len, cnt;
double d, rag;
double x1, x2;
double isl[MAX][2];
double roc[MAX][2];

int main(){
	scanf("%d %lf", &T, &d);
	while(T != 0){
		len = 0;
		cnt = 0;
		for(int i = 0; i < T; i++, len++)
			scanf("%lf %lf", &isl[i][0], &isl[i][1]);

		for(int i = 0; i < len; i++){
			if(isl[i][1] < 0 || isl[i][1] > d){
				cnt = -1;
				break;
			}
			rag = sqrt(d * d - isl[i][1] * isl[i][1]);
			x1 = isl[i][0] - rag;
			x2 = isl[i][0] + rag;
			int isin = 0;
			for(int j = 0; cnt && j < cnt; j++)//first find whether in range, if so, restrict range
				if(x2 >= roc[j][0] && x1 <= roc[j][1]){
					roc[j][0] = max(x1, roc[j][0]);
					roc[j][1] = min(x2, roc[j][1]);
					isin = 1;
					break;
				}
			if(!isin){
				roc[cnt][0] = x1;
				roc[cnt][1] = x2;
				cnt++;
			}
		}
		
		printf("Case %d: %d\n", cas++, cnt);
		scanf("%d %lf", &T, &d);
	}
}