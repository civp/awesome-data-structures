// #1033 interlaced sum, DP
// We have f(a_0 a_1...a_(n-1)) = a_0 - f(a_1...a_(n-1))
// define state sum[i][j][k]: sum_x [f(x)=k]x, for x in [0, (j+1)*10^i)
// sum[i][j][k] = sum[i][j-1][k] + sum[i-1][9][j-k] + j * pow(10,i) * cnt[i-1][9][j-k]
// where cnt[i][j][k] = cnt[i][j-1][k] + cnt[i-1][9][j-k]
#include <cstdio>

#define MOD 1000000007

int main()
{
	long long l, r;
	int k;
	scanf("%lld %lld %d", &l, &r, &k);
	
	return 0;
}