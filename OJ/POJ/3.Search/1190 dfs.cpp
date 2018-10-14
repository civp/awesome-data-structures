#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ans = 0;

void dfs(int m, int leftV, int A, int lastR, int lastH){
	if(m * (lastR - 1) * (lastR - 1) * (lastH - 1) < leftV && m != M)
		return;
	if(leftV < 0)
		return;
	if(ans && A > ans)
		return;
	if(!m){
		if(!leftV && (A < ans || !ans))
			ans = A;
		return;
	}

	//try the sample
	//from down to up
	//initially we get r = 99, h = 999, leftV is 100
	//assume there's a (99, 999) cylinder
	//cause ans == 0, we dfs
	//in the next layer(m - 1), we update leftV and A
	//sadly leftV is negative, return
	//we decrease h till leftV >= 0
	//we can see that ans is 0 till m == 0
	//the first valid(consider leftV only) value for (r, h) is (10, 1)
	//in fact we did lots of trash work
	//sadly, 
	for(int r = lastR - 1; r >= m; --r)
		for(int h = lastH - 1; h >= m; --h){
			int curV = r * r * h;//current volume
			int curA = 2 * r * h;//current area
			if(m == M)
				curA += r * r;//top area
			if(A + 2 * leftV / r > ans && ans)//reach layer i, i - 1
				continue;
			dfs(m - 1, leftV - curV, A + curA, r, h);//dfs
		}
}

int main(){
	cin >> N >> M;
	dfs(M, N, 0, 100, 1000);
	cout << ans << endl;
}