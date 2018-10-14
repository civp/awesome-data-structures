#include <iostream>
using namespace std;

int main(){
	int size;
	cin >> size;
	int tri[size][size];
	for(int i = 0; i < size; ++i)
		for(int j = 0; j <= i; ++j)
			cin >> tri[i][j];

	for(int i = size - 2; i >= 0; --i)
		for(int j = 0; j <= i; ++j)
			tri[i][j] += max(tri[i + 1][j], tri[i + 1][j + 1]);
	cout << tri[0][0] << endl;
}