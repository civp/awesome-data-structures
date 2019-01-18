#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, w;
	scanf("%d %d", &n, &w);

	int low = 0, up = w, sum = 0;
	for (int i = 0; i < n; ++i) {
		int cur;
		scanf("%d", &cur);
		sum += cur;
		if (sum > 0 && w - sum < up)
			up = w - sum; 
		else if (sum < 0 && -sum > low)
			low = -sum;
	}

	if (up - low + 1 > 0)
		printf("%d\n", up - low + 1);
	else
		printf("0\n");
}