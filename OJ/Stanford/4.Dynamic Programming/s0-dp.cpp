#include <iostream>
#define MAX 10000
using namespace std;

int d[MAX];
int N;

int main(){
	cin >> N;
	d[0] = d[1] = d[2] = 1;
	d[3] = 2;
	for(int i = 4; i <= N; ++i)
		d[i] = d[i - 1] + d[i - 3] + d[i - 4];
	cout << d[N] << endl;
}