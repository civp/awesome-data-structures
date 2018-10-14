#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10010;
int a[MAX];

int main() {
	int cnt = 0;
	for (int i = 1; i < 10; ++i)
		a[++cnt] = i * 10 + 10 - i;
	for (int i = 1; i < 10; ++i)
		for (int j = 0; j <= 10 - i; ++j)
			a[++cnt] = i * 100 + j * 10 + 10 - i - j;
	for (int i = 1; i < 10; ++i)
		for (int j = 0; j <= 10 - i; ++j)
			for (int k = 0; k <= 10 - i - j; ++k)
				a[++cnt] = i * 1000 + j * 100 + k * 10 + 10 - i - j - k;
	for (int i = 1; i < 10; ++i)
		for (int j = 0; j <= 10 - i; ++j)
			for (int k = 0; k <= 10 - i - j; ++k)
				for (int m = 0; m <= 10 - i - j - k; ++m)
					a[++cnt] = i * 10000 + j * 1000 + k * 100 + m * 10 + 10 - i - j - k - m;
	for (int i = 1; i < 10; ++i)
		for (int j = 0; j <= 10 - i; ++j)
			for (int k = 0; k <= 10 - i - j; ++k)
				for (int m = 0; m <= 10 - i - j - k; ++m)
					for (int n = 0; n <= 10 - i - j - k - m; ++n)
						a[++cnt] = i * 100000 + j * 10000 + k * 1000 + m * 100 + n * 10 + 10 - i - j - k - m - n;
	for (int i = 1; i < 10; ++i)
		for (int j = 0; j <= 10 - i; ++j)
			for (int k = 0; k <= 10 - i - j; ++k)
				for (int m = 0; m <= 10 - i - j - k; ++m)
					for (int n = 0; n <= 10 - i - j - k - m; ++n)
						for (int h = 0; h <= 10 - i - j - k - m - n; ++h)
							a[++cnt] = i * 1000000 + j * 100000 + k * 10000 + m * 1000 + n * 100 + h * 10 + 10 - i - j - k - m - n - h;
	for (int i = 1; i < 2; ++i)
		for (int j = 0; j <= 10 - i; ++j)
			for (int k = 0; k <= 10 - i - j; ++k)
				for (int m = 0; m <= 10 - i - j - k; ++m)
					for (int n = 0; n <= 10 - i - j - k - m; ++n)
						for (int h = 0; h <= 10 - i - j - k - m - n; ++h)
							for (int g = 0; cnt < MAX && g <= 10 - i - j - k - m - n - h; ++g)
								a[++cnt] = i * 10000000 + j * 1000000 + k * 100000 + m * 10000 + n * 1000 + h * 100 + g * 10 + 10 - i - j - k - m - n - h - g;
	for (int i = 0; i <= cnt; ++i)
		cout << a[i] << ",";
	cout << endl << cnt << endl;
}