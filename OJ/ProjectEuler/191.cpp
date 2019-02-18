// DP, overlapping subproblems
// Project Euler #191
// exchange A and L
#include <cstdio>
#include <cstring>

int main()
{
    int N;
    scanf("%d", &N);
    if (N == 1)
    {
        printf("3");
        return 0;
    }
    long long a[2][4]; // #A and Last2Word ** *L L* LL
    a[0][0] = a[0][1] = a[0][2] = a[0][3] = a[1][1] = a[1][2] = 1; // strlen = 2
    a[1][0] = 2;
    a[1][3] = 0;
    long long b[2][4];
    for (int i = 3; i <= N; ++i)
    {
        b[0][0] = a[0][0] + a[0][2]; // append O, OO
        b[0][1] = a[0][0] + a[0][2]; // append L, OL
        b[0][2] = a[0][1] + a[0][3]; // append O, LO
        b[0][3] = a[0][1]; // append L, LL
        b[1][0] = a[0][0] + a[0][2] + a[1][0] + a[1][2]; // append A/O
        b[1][1] = a[1][0] + a[1][2]; // append L
        b[1][2] = a[0][1] + a[0][3] + a[1][1] + a[1][3]; // append A/O
        b[1][3] = a[1][1]; // append L
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 4; ++k)
                a[j][k] = b[j][k]; // incorrect if overflow
    }
    long long ans = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 4; ++j)
            ans += a[i][j];
    printf("%d", ans);
    return 0;
}