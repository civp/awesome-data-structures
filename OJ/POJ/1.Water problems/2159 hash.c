#include <stdio.h>
#define MAX 26

int main(){
	int anum[MAX] = {0}, bnum[MAX] = {0};
	char c; 
	while((c = getchar()) != '\n')
		anum[c - 'A']++;
	while((c = getchar()) != '\n')
		bnum[c - 'A']++;
	int ahash = 0, bhash = 0;
	for(int i = 0; i < MAX; i++){
		ahash += anum[i] * anum[i];
		bhash += bnum[i] * bnum[i];
	}
	if(ahash == bhash)
		printf("YES");
	else
		printf("NO");

	return 0;
}