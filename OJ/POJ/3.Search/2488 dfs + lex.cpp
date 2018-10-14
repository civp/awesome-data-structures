#include <iostream>
using namespace std;

int p, q;//py qx
int cnt;
char ans[52];
bool chessboard[26][26];
int mx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};//lexicographically!
int my[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void init(int p, int q){
	for(int i = 0; i < q; ++i)
		for(int j = 0; j < p; ++j)
			chessboard[i][j] = false;
}

void reset(){
	for(int i = 0; i < 52; ++i)
		ans[i] = 0;
}

void dfs(int x, int y){	
	if(cnt == p * q * 2)
		return;
	
	for(int i = 0; i < 8; ++i){
		int px = x + mx[i];
		int py = y + my[i];
		if(px >= 0 && px < q && py >= 0 && py < p && !chessboard[px][py]){
			//mark
			chessboard[px][py] = true;
			ans[cnt++] = px + 'A';
			ans[cnt++] = py + '1';
			dfs(px, py);
			//one solution
			if(cnt == p * q * 2)
				return;
			//backtrack
			chessboard[px][py] = false;
			ans[--cnt] = 0;
			ans[--cnt] = 0;
		}
	}
}

int main(){
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i){
		cin >> p >> q;
		init(p, q);
		reset();
		cnt = 2;
		chessboard[0][0] = true;
		ans[0] = 'A';
		ans[1] = '1';
		dfs(0, 0);
		cout << "Scenario #" << i << ':' << endl;
		if(cnt != p * q * 2)
			cout << "impossible" << endl;
		else
			cout << ans << endl;
		cout << endl;
	}
	return 0;
}