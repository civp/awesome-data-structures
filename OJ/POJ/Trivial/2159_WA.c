#include <stdio.h>
#include <string.h>
const int MAX = 100;

int main(){
	char enc[MAX], pro[MAX];
	int ans, len;

	gets(enc);
	gets(pro);
	len = strlen(enc);

	for(int i = 0; i < len; i++){
		ans = 0;
		if(pro[i] == 'Z')
			pro[i] = 'A';
		if(pro[i] >= 'A' && pro[i] < 'Z')//not necessarily shift
			pro[i]++;
		for(int j = 0; j < len; j++)
			if(enc[j] == pro[i]){
				enc[j] = '1';
				ans = 1;
				break;
			}
		if(!ans)
			break;
	}
	if(!ans)
		printf("NO");
	else
		printf("YES");
}