// DP, overlapping subproblems
#include <cstdio>
#define MOD 1000000007

// int calc(int remlen, int na, int ncl)
// {
//     int cnta = 0, cntl = 0, cnto = 0;
//     // if (na == 2 || ncl == 3)
//         // return 0;
//     if (!remlen)
//         return 1;
//     if (na < 1)
//         cnta = calc(remlen - 1, na + 1, ncl);
//     if (ncl < 3)
//         cntl = calc(remlen - 1, na, ncl + 1);
//     cnto = calc(remlen - 1, na, 0);
//     return (cnta + cntl + cnto) % MOD;
// }

int main()
{
    int N;
    scanf("%d", &N);
    // a[0][x][x] = 0; a[x][2][x] = 0; a[x][x][3] = 0;
    int a[3][4]; // State na = i, ncl = j;
    // a[i][j] = a[i + 1][j] + a[i][j + 1] + a[i][0]; TODO:a[i][0]?
    for (int i = 0; i < 3; ++i) // Start from length 0
        for (int j = 0; j < 4; ++j)
            a[i][j] = 0;
    for (int i = 1; i < N; ++i) // length
        for (int j = 1; j >= 0; --j) // number of A
            for (int k = 2; k >= 0; --k) // number of continuous L
                a[j][k] = (a[j + 1][k] + a[j][k + 1] + a[j][0]) % MOD;
    int ans = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            ans = (ans + a[i][j]) % MOD;
    printf("%d", ans);
    return 0;
    // printf("%d", calc(N, 0, 0));
}