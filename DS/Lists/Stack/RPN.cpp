// Reverse Poland Notation
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	stack<double> s;
	bool validInput = true;
	for (auto c : str)
	{
		if (isdigit(c))
			s.push(c - '0');
		else if (c == '+') // TODO: simplify it using templates
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
			validInput= false;
			break;
		}
	}

	if (!validInput || s.size() != 1)
		cout << "Wrong Input!" << endl;
	else
	{
		double res = s.top();
		s.pop();
		cout.setf(ios::fixed);
		cout << "Answer: " << fixed << setprecision(6) << res << endl;
	}

	return 0;
}