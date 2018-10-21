#include <iostream>
using namespace std;

int N, res;
int poo[3] = {1, 3, 4};

void dfs(int rem){
	if(!rem){
		++res;
		return;
	}
	for(int i = 0; i < 3; ++i)
		if(rem >= poo[i])
			dfs(rem - poo[i]);
}

int main(){
	cin >> N;// assume N >= 0
	dfs(N);
	cout << res << endl;
}