#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int main(){
	int T;
	int cnt = 1;
	scanf("%d", &T);
	while(T--){
		double R;
		int n;
		scanf("%lf %d", &R, &n);
		printf("Scenario #%d:\n", cnt++);
		//why %.3lf wa?
		printf("%.3f\n\n", R * sin(PI / (double)n));
	}
}