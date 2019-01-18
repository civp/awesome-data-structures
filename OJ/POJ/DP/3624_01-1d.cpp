#include <iostream>
#define MAX 3402
#define MAXW 12881
using namespace std;

int N, M;
int w[MAX];
int d[MAX];
int maxDes[MAXW];

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; ++i)
		cin >> w[i] >> d[i];
	for(int i = 0; i < N; ++i)
		for(int aw = M; aw >= w[i]; --aw)
			maxDes[aw] = max(maxDes[aw], maxDes[aw - w[i]] + d[i]);
	cout << maxDes[M] << endl;
}