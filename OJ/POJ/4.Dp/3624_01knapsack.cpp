#include <iostream>
#define MAX 3402
#define MAXW 12881
using namespace std;

int N, M;
int w[MAX];
int d[MAX];
int m[MAX][MAXW];

int maxDes(int i, int aw){
	if(m[i][aw])
		return m[i][aw];
	if(i == 0){
		if(w[i] <= aw){
			m[i][aw] = d[i];
			return d[i];
		}
		else{
			m[i][aw] = 0;
			return 0;
		}
	}
	int without_i = maxDes(i - 1, aw);
	int with_i;
	if(w[i] > aw){
		m[i][aw] = without_i;
		return without_i;
	}
	else
		with_i = d[i] + maxDes(i - 1, aw - w[i]);
	int res = max(without_i, with_i);
	m[i][aw] = res;
	return res;
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; ++i)
		cin >> w[i] >> d[i];
	cout << maxDes(N - 1, M) << endl;
}