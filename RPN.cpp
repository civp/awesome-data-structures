#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <stack>
#include <windows.h>
using namespace std;

int main()
{
	string str; // Reverse portland
	getline(cin, str);

	stack<double> s;
	for (auto c : str)
	{
		if (isdigit(c))
			s.push(c - '0');
		else if (c == '+')
		{
			double e1 = s.top();
			s.pop();
			double e2 = s.top();
			s.pop();
			s.push(e2 + e1);
		}
		else if (c == '-')
		{
			double e1 = s.top();
			s.pop();
			double e2 = s.top();
			s.pop();
			s.push(e2 - e1);
		}
		else if (c == '*')
		{
			double e1 = s.top();
			s.pop();
			double e2 = s.top();
			s.pop();
			s.push(e2 * e1);
		}
		else if (c == '/')
		{
			double e1 = s.top();
			s.pop();
			double e2 = s.top();
			s.pop();
			s.push(e2 / e1);
		}
		else
		{
			cout << "Wrong Input!" << endl;
			break;
		}
	}

	double res = s.top();
	s.pop();
	cout.setf(ios::fixed);
	cout << "Answer: " << fixed << setprecision(6) << res << endl;

	system("pause");

	return 0;
}