#include <stdio.h>

char trans(char c){
	char ret;
	if(c == ' ')
		ret = 0;
	else
		ret = c - 'A' + 1;
	return ret;
}

int main(){
	int idx;
	int ans;
	while((char c = getchar()) != '#'){
		ans = trans(c);
		idx = 2;
		while((c = getchar()) != '\n'){
			ans += trans(c) * idx;
			idx++;
		}
		printf("%d\n", ans);	
	}
}