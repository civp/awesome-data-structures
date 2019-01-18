#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int tmp;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		sum1 += tmp;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		sum2 += tmp;
	}

	if (sum1 < sum2)
		cout << "No";
	else
		cout << "Yes";
	
	return 0;
}