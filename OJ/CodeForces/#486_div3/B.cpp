#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{
	return a.length() < b.length();
}

int main()
{
	int n;
	cin >> n;

	vector<string> v;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), comp);

	bool flag = true;
	for (int i = 0; i < n - 1; ++i)
	{
		string cur = v[i];
		string nxt = v[i + 1];
		size_t pos = nxt.find(cur);
		if (pos == string::npos)
		{
			flag = false;
			break;
		}
	}

	if (flag)
	{
		cout << "YES" << endl;
		for (auto i : v)
			cout << i << endl;
	}
	else
		cout << "NO";
}