#include <iostream>
#include <cstdio>
#define MAX 1000
using namespace std;

void init(int *s, int n){
	for(int i = n; i > 0; --i)
		s[i] = -1;//height
}

void join(int *s, int a, int b){
	if(s[b] < s[a])//b is deeper
		s[a] = b;
	else{
		if(s[a] == s[b])
			--s[a];
		s[b] = a;
	}
}

int main(){
	int n, m;
	int s[MAX];
	cin >> n >> m;
	while(n){
		init(s, n);
		while(m--){
			int a, b;
			cin >> a >> b;
			join(s, a, b);
		}
		int cnt = 0;
		for(int i = 0; i < n; ++i)
			if(s[i] <= 0)
				++cnt;
		cout << cnt - 1 << endl;
		cin >> n >> m;
	}
	return 0;
}