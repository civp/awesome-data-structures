#include <stdio.h>
#define X 4
#define Y 4
#define MAX 16

char rev(char c){
	return (c == 'b') ? 'w' : 'b';
}

int flip(char sou[][Y], int ope[]){
	char tab[X][Y];
	for(int i = 0; i < X; i++)
		for(int j = 0; j < Y; j++)
			tab[i][j] = sou[i][j];
	
	for(int i = 0; i < X; i++)
		for(int j = 0; j < Y; j++)
			if(ope[i * Y + j]){
				tab[i][j] = rev(tab[i][j]);
				if(i > 0)
					tab[i - 1][j] = rev(tab[i - 1][j]);
				if(i < X - 1)
					tab[i + 1][j] = rev(tab[i + 1][j]);
				if(j > 0)
					tab[i][j - 1] = rev(tab[i][j - 1]);
				if(j < Y - 1)
					tab[i][j + 1] = rev(tab[i][j + 1]);
			}

	char tmp = tab[0][0];
	for(int i = 0; i < X; i++)
		for(int j = 0; j < Y; j++)
			if(tab[i][j] != tmp)
				return 0;

	return 1;
}

int main(){
	char tab[X][Y];
	char tmp[X][Y + 1];
	int ope[MAX];
	int cnt = 0;
	int min = MAX;
	int sta = 0;
	for(int i = 0; i < X; i++)
		for(int j = 0; j < Y + 1; j++)
			scanf("%c", &tmp[i][j]);
	for(int i = 0; i < X; i++)
		for(int j = 0; j < Y; j++)
			tab[i][j] = tmp[i][j];

	for(ope[0] = 0; ope[0] < 2; ope[0]++)
		for(ope[1] = 0; ope[1] < 2; ope[1]++)
			for(ope[2] = 0; ope[2] < 2; ope[2]++)
				for(ope[3] = 0; ope[3] < 2; ope[3]++)
					for(ope[4] = 0; ope[4] < 2; ope[4]++)
						for(ope[5] = 0; ope[5] < 2; ope[5]++)
							for(ope[6] = 0; ope[6] < 2; ope[6]++)
								for(ope[7] = 0; ope[7] < 2; ope[7]++)
									for(ope[8] = 0; ope[8] < 2; ope[8]++)
										for(ope[9] = 0; ope[9] < 2; ope[9]++)
											for(ope[10] = 0; ope[10] < 2; ope[10]++)
												for(ope[11] = 0; ope[11] < 2; ope[11]++)
													for(ope[12] = 0; ope[12] < 2; ope[12]++)
														for(ope[13] = 0; ope[13] < 2; ope[13]++)
															for(ope[14] = 0; ope[14] < 2; ope[14]++)
																for(ope[15] = 0; ope[15] < 2; ope[15]++)
																	if(flip(tab, ope)){
																		sta = 1;
																		cnt = 0;
																		for(int i = 0; i < MAX; i++)
																			if(ope[i])
																				cnt++;
																		min = (min > cnt) ? cnt : min;
																	}

	if(sta)
		printf("%d", min);
	else
		printf("Impossible");
	return 0;
}