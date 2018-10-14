#include <iostream>
#include <queue>
#define MAX 100000
//judge is x valid first to avoid transborder
#define judge(x) ((x) >= 0 && (x) <= MAX && !v[x])
using namespace std;

int N, K;
int d[MAX + 1];
int v[MAX + 1];
queue<int> q;

void bfs(int n){
	//initialization
	//every node has two arguments d and v
	d[n] = 0;
	q.push(n);
	v[n] = 1;
	//two way to end
	//exhaust all possibility
	//or find the solution
	while(!q.empty()){
		//deal with the front
		int x = q.front();
		q.pop();
		//end judge
		if(x == K)
			break;
		//bfs
		if(judge(x + 1)){
			q.push(x + 1);
			d[x + 1] = d[x] + 1;
			v[x + 1] = 1;
		}
		if(judge(x - 1)){
			q.push(x - 1);
			d[x - 1] = d[x] + 1;
			v[x - 1] = 1;
		}
		if(judge(x * 2)){
			q.push(x * 2);
			d[x * 2] = d[x] + 1;
			v[x * 2] = 1;
		}
	}
}

int main(){
	cin >> N >> K;
	bfs(N);
	cout << d[K] << endl;
}