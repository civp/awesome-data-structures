#include <iostream>
using namespace std;

int main(){
	int d[31];
	d[0] = 1;
	d[1] = 0;
	d[2] = 3;
	d[3] = 0;
	for(int i = 4; i < 31; ++i)
		d[i] = 4 * d[i - 2] - d[i - 4];
	int t;
	cin >> t;
	while(t != -1){
		cout << d[t] << endl;
		cin >> t;
	}
}