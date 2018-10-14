#include <iostream>
#include <string>
using namespace std;

int main(){
	int len;
	cin >> len;
	string s;
	cin >> s;
	short ans[len][len];
	for(int i = 0; i < len; ++i)
		ans[i][i] = 0;
	for(int i = 1; i < len; ++i)
		ans[i][i - 1] = 0;
	for(int k = 1; k < len; ++k)
		for(int i = 0, j = i + k; j < len; ++i, ++j){//fill up triangle
			if(s[i] != s[j])
				ans[i][j] = 1 + min(ans[i + 1][j], ans[i][j - 1]);
			else
				ans[i][j] = ans[i + 1][j - 1];
		}
	cout << ans[0][len - 1] <<endl;
}