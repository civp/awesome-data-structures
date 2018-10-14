#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 101;

int main() {
	int n, ans = 0;
	char a[MAX];
	scanf("%d", &n);
	getchar();
	gets(a);
	for (int i = 0; i < n; ++i)	
		if (a[i] == '0')
			++ans;
	putchar('1');
	for (int i = 0; i < ans; ++i)
		putchar('0');
}