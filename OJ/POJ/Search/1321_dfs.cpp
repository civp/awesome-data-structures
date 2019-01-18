#include <iostream>
#include <cstring>
#define MAX 8
#define mem(a) memset(a, 0, sizeof(a))
using namespace std;

int N, K, C;
int len;
int avlb[MAX][MAX];
int rownum[MAX];
bool visy[MAX];

void dfs(int r, int cnt){//use cnt here, or global
	if(cnt == K){
		++C;
		return;
	}
	if(r == N || K - cnt > N - r)
	 	return;

	for(int j = 0; j < rownum[r]; ++j){
		int y = avlb[r][j];
		if(!visy[y]){
			visy[y] = true;
			dfs(r + 1, cnt + 1);
			visy[y] = false;//backtrack should be right after dfs
		}
	}
	dfs(r + 1, cnt);//if no available y, r should +1 anyway
}

int main(){
	cin >> N >> K;
	while(N != -1){
		C = 0;
		mem(visy);
		mem(avlb);
		mem(rownum);
		len = 0;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j){
				char c;
				cin >> c;
				if(c == '#')
					avlb[i][rownum[i]++] = j;
			}
		dfs(0, 0);
		cout << C << endl;
		cin >> N >> K;
	} 
}