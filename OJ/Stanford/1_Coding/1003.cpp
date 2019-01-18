#include <iostream>
using namespace std;

int main(){
	double len;
	cin >> len;
	while(len){
		int sum = 0, cnt = 0;
		for(int i = 2; sum < len; ++i){
			sum += 1 / (double)i;
			++cnt;
		}
		cout << cnt << ' ' << "card(s)" << endl;
		cin >> len;
	}
}