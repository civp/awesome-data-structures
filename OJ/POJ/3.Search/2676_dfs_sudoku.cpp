#include <iostream>
#include <cstring>
#define LEN 9
#define mem(a) memset(a, 0, sizeof(a))
using namespace std;

int T;
int zero;
int cnt;
int sudoku[LEN][LEN];
int rowNum[LEN];
int fsbPos[LEN][LEN];
bool ban[LEN][LEN];

void dfs(int row){
	if(cnt == zero)
		return;
	for(int i = 0; i < rowNum[row]; ++i)
		for(int k = 1; k < 10; ++k){
			if(!ban[row][k]){
				ban[row][k] = true;
				sudoku[row][fsbPos[row][i]] = k;
				++cnt;
				dfs(row + 1);
				if(cnt == zero)
					return;
				--cnt;
				sudoku[row][fsbPos[row][i]] = 0;
				ban[row][k] = false;
			}
		}
	dfs(row + 1);
	if(cnt == zero)
		return;
}

int main(){
	cin >> T;
	while(T--){
		mem(sudoku);
		mem(rowNum);
		mem(fsbPos);
		mem(ban);
		zero = 0;
		for(int i = 0; i < LEN; ++i)
			for(int j = 0; j < LEN; ++j){
				char c;
				cin >> c;
				sudoku[i][j] = c - '0';
				if(c == '0'){
					++zero;
					fsbPos[i][rowNum[i]++] = j;
				}
				else
					ban[i][c - '0'] = true;
			}
		dfs(0);
		for(int i = 0; i < LEN; ++i){
			for(int j = 0; j < LEN; ++j)
				cout << sudoku[i][j];
			cout << endl;
		}
	}
}