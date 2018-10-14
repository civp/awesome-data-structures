#include <stdio.h>
#define LEN 4
#define min(x, y) (x < y ? x : y) 
int map[LEN][LEN];
char tmp[LEN + 1];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int flag = 0;
int step = 0x3f3f3f3f;

int check(){
	int cap = map[0][0];
	for(int i = 0; i < LEN; i++)
		for(int j = 0; j < LEN; j++)
			if(cap != map[i][j])
				return 0;
	return 1;
}

void flip(int x, int y){
	map[x][y] = !map[x][y];
	for(int i = 0; i < LEN; i++){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(tx >= 0 && tx < LEN && ty >= 0 && ty < LEN)
			map[tx][ty] = !map[tx][ty];
	}
}

void dfs(int m, int cnt){//dfs traversal
	if(m > LEN * LEN - 1){
		if(check()){
			step = min(cnt, step);
			flag = 1;
		}
		return;
	}
	if(check()){
		step = min(cnt, step);
		flag = 1;
		return;
	}
	int x = m / LEN;
	int y = m % LEN;
	dfs(m + 1, cnt);//if not flip
	flip(x, y);
	dfs(m + 1, cnt + 1);//if flip
	flip(x, y);//backtrack
	return;
}

int main(){
	for(int i = 0; i < LEN; i++){
		scanf("%s", tmp);
		for(int j = 0; j < LEN; j++)
			map[i][j] = tmp[j] == 'b' ? 1 : 0;
	}

	dfs(0, 0);

	if(flag)
		printf("%d", step);
	else
		printf("Impossible");
	return 0;
}