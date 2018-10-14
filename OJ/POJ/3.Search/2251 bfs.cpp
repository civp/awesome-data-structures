#include <iostream>
#include <cstring>
#include <queue>
#define MAX 30
#define mem(a) memset(a, 0, sizeof(a))
using namespace std;

int ml[6] = {1, 0, 0, 0, 0, -1};
int mr[6] = {0, 1, 0, 0, -1, 0};
int mc[6] = {0, 0, 1, -1, 0, 0};
char dun[MAX][MAX][MAX];
int step[MAX][MAX][MAX];
bool vis[MAX][MAX][MAX];
char ch;
int lay, row, col;
int flag;
struct cod{
	int l;
	int r;
	int c;
};
cod s, e;
queue<cod> q;

int judge(cod tmp){
	return (tmp.l >= 0 && tmp.l < lay && tmp.r >= 0 && tmp.r < row && tmp.c >=0 && tmp.c < col
			&& dun[tmp.l][tmp.r][tmp.c] != '#' && !vis[tmp.l][tmp.r][tmp.c]);
}

void bfs(){
	vis[s.l][s.r][s.c] = true;
	q.push({s.l, s.r, s.c});
	step[s.l][s.r][s.c] = 0;

	while(!q.empty()){
		cod pos = q.front();
		q.pop();
		if(pos.l == e.l && pos.r == e.r && pos.c == e.c)
			break;
		for(int i = 0; i < 6; ++i){
			cod tmp = {pos.l + ml[i], pos.r + mr[i], pos.c + mc[i]};
			if(judge(tmp)){
				q.push(tmp);
				vis[tmp.l][tmp.r][tmp.c] = 1;
				step[tmp.l][tmp.r][tmp.c] = step[pos.l][pos.r][pos.c] + 1;
			}
		}
	}
}

int main(){
	cin >> lay >> row >> col;
	while(lay){
		mem(dun);
		mem(step);
		mem(vis);
		flag = 0;
		for(int i = 0; i < lay; ++i)
			for(int j = 0; j < row; ++j)
				for(int k = 0; k < col; ++k){
					cin >> ch;
					dun[i][j][k] = ch;
					if(ch == 'S'){
						s.l = i;
						s.r = j;
						s.c = k;
					}
					if(ch == 'E'){
						e.l = i;
						e.r = j;
						e.c = k;
					}
				}
		bfs();
		if(step[e.l][e.r][e.c])
			cout << "Escaped in " << step[e.l][e.r][e.c]
				 << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
		//clear queue, or there will be some fucking cache
		//u may go to exit next step, then WA
		while(!q.empty())
			q.pop();
		cin >> lay >> row >> col;
	}
}