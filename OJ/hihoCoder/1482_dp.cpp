// DP, overlapping subproblems
// Project Euler #191
#include <cstdio>
#include <cstring>
#define MOD 1000000007

int main()
{
    int N;
    scanf("%d", &N);
    if (N == 1)
    {
        printf("3");
        return 0;
    }
    unsigned int a[2][4]; // #A and Last2Word ** *L L* LL
    a[0][0] = a[0][1] = a[0][2] = a[0][3] = a[1][1] = a[1][2] = 1; // strlen = 2
    a[1][0] = 2;
    a[1][3] = 0;
    unsigned int b[2][4];
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
                a[j][k] = b[j][k] % MOD; // incorrect if overflow
    }
    long long ans = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 4; ++j)
            ans += a[i][j];
    printf("%d", ans % MOD);
    return 0;
}

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

// int main()
// {
//     int N;
//     scanf("%d", &N);
//     // a[0][x][x] = 0; a[x][2][x] = 0; a[x][x][3] = 0;
//     int a[3][4]; // State na = i, ncl = j;
//     // a[i][j] = a[i + 1][j] + a[i][j + 1] + a[i][0]; TODO:a[i][0]?
//     for (int i = 0; i < 3; ++i) // Start from length 0
//         for (int j = 0; j < 4; ++j)
//             a[i][j] = 0;
//     for (int i = 1; i < N; ++i) // length
//         for (int j = 1; j >= 0; --j) // number of A
//             for (int k = 2; k >= 0; --k) // number of continuous L
//                 a[j][k] = (a[j + 1][k] + a[j][k + 1] + a[j][0]) % MOD;
//     int ans = 0;
//     for (int i = 0; i < 3; ++i)
//         for (int j = 0; j < 4; ++j)
//             ans = (ans + a[i][j]) % MOD;
//     printf("%d", ans);
//     return 0;
//     // printf("%d", calc(N, 0, 0));
// }