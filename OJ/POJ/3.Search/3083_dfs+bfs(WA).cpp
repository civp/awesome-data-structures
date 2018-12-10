#include <iostream>
#include <queue>
#include <cstring>
#define mem(a) (memset(a, 0, sizeof(a)))
using namespace std;

char maze[40][40];
bool is_vis[40][40];
//maze parameter
int w, h;
int sx, sy;
int ex, ey;
//define left according to start
int diru[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int dirl[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
int dirr[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
int dird[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
int (*dir)[2];
struct node
{
	int x, y;
	int dist;
};

void decide_dir(){
	if(sx == 0)
		dir = diru;
	else if(sx == h - 1)
		dir = dird;
	else if(sy == 0)
		dir = dirl;
	else
		dir = dirr;
}

int lpath(int x, int y){
	static int step = 0;
	if(x == ex && y == ey)
		return 1;
	for(int i = 0; i < 4; ++i){
		int new_x = x + dir[i][0];
		int new_y = y + dir[i][1];
		if(maze[new_x][new_y] == '.' && !is_vis[new_x][new_y]){
			is_vis[new_x][new_y] = true;
			//dfs
			step = lpath(new_x, new_y) + 1;
			if(new_x == ex && new_y == ey)
				return step;
			//backtrack
			maze[new_x][new_y] = '.';
			--step;
		}
	}
}

int rpath(int x, int y){
	static int step = 0;
	if(x == ex && y == ey)
		return 1;
	for(int i = 3; i >= 0; --i){
		int new_x = x + dir[i][0];
		int new_y = y + dir[i][1];
		if(maze[new_x][new_y] == '.' && !is_vis[new_x][new_y]){
			is_vis[new_x][new_y] = true;
			//dfs
			step = rpath(new_x, new_y) + 1;
			if(new_x == ex && new_y == ey)
				return step;
			//backtrack
			maze[new_x][new_y] = '.';
			--step;
		}
	}
}

int short_path(int x, int y){
	mem(is_vis); 
	static int step = 0;
	queue<node> q;
	node u;
	u.x = x;
	u.y = y;
	u.dist = 0;
	is_vis[u.x][u.y] = true;
	q.push(u);
	while(!q.empty()){
		u = q.front();
		int d = u.dist;
		if(maze[u.x][u.y] == 'E')
			return u.dist;
		q.pop();
		for(int i = 0; i < 4; ++i){
			node v;
			v.x = u.x + dir[i][0];
			v.y = u.y + dir[i][1];
			if(maze[v.x][v.y] == '.' && !is_vis[v.x][v.y]){
				is_vis[v.x][v.y] = true;
				v.dist = d + 1;
				q.push(v);
			}
		}
	}
	return 0;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> w >> h;
		for(int i = 0; i < w; ++i)
			for(int j = 0; j < h; ++j){
				//input may have problems
				cin >> maze[i][j];
				if(maze[i][j] == 'S'){
					sx = i;
					sy = j;
				}
				if(maze[i][j] == 'E'){
					ex = i;
					ey = j;
				}
			}
		decide_dir();
		cout << lpath(sx, sy) << " " << rpath(sx, sy)
			 << " " << short_path(sx, sy) << endl;
	}
}