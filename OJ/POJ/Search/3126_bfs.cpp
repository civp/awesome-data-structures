#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#define MAX 10000
#define mem(a) memset(a, 0, sizeof(a))
using namespace std;

int T;
int sta, exi;
int mov[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
queue<int> q;
bool vis[MAX];
int dis[MAX];
int pow_10[4] = {1, 10, 100, 1000};

bool isprime(int x){
	int ret = true;
	for(int i = 2; i <= sqrt(x); ++i){
		if(x % i == 0){
			ret = false;
			break;
		}
	}
	return ret;
}

bool judge(int x){
	return (x > 1000 && x < 9999 && !vis[x] && isprime(x));//forgot checking vis
}

void bfs(){
	q.push(sta);
	vis[sta] = true;
	dis[sta] = 0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if(cur == exi){
			cout << dis[cur] << endl;
			while(!q.empty())
				q.pop();
			break;
		}
		for(int i = 3; i >= 0; --i)
			for(int j = 0; j < 10; ++j){
				int tmp = cur + (mov[j] - cur / pow_10[i] % 10) * pow_10[i]; 
				if(judge(tmp)){
					q.push(tmp);
					vis[tmp] = true;
					dis[tmp] = dis[cur] + 1;
				}
			}
	}//forgot to write impossible, but maybe it's solvable for any cases
}

int main(){
	cin >> T;
	while(T--){
		mem(vis);mem(dis);
		cin >> sta >> exi;
		bfs();
	}
}