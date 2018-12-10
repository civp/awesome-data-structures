#include <stdio.h>
#include <string.h>
#define MAX 10000
char a[MAX], b[MAX];

void build(int n, char *a, char *b){
    if(n <= 0)
        return;
    else{
        int p = strchr(b, a[0]) - b;
        build(p, a + 1, b);
        build(n - 1 - p, a + p + 1, b + p + 1);
        printf("%c", a[0]);
    }
}

int main(){
    while(scanf("%s %s", a, b) != EOF){
        int n = strlen(a);
        build(n, a, b);
        printf("\n");
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }
}