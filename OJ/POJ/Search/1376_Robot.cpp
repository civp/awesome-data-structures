#include <cstdio>
#include <cstring>
#include <queue>
// wa

const int INF = 0x3f3f3f3f;
const int THRESHOLD = 20;

int M, N;
bool grid[50][50];
int res[51][51];

struct Position
{
    int x;
    int y;
    int ort;
    int time;
    Position(int x, int y, int ort, int time)
    {
        this->x = x;
        this->y = y;
        this->ort = ort;
        this->time = time;
    }
};

bool operator < (const Position &p1, const Position &p2) 
{
    return p1.time < p2.time;
}

int main()
{
    scanf("%d %d", &M, &N);
    while (M != 0 || N != 0)
    {
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
            {
                int tmp;
                scanf("%d", &tmp);
                grid[i][j] = tmp;
            }
        int b1, b2, e1, e2;
        scanf("%d %d %d %d", &b1, &b2, &e1, &e2);
        int ort;
        char tmp[8];
        scanf("%s", tmp);
        switch (tmp[0])
        {
            case 'n': ort = 0; break;
            case 'w': ort = 1; break;
            case 's': ort = 2; break;
            case 'e': ort = 3; break;
        }

        memset(res, 0x3f, sizeof(res)); // set inf

        // bfs
        std::queue<Position> q;
        Position bg(b1, b2, ort, 0);
        q.push(bg);
        while (!q.empty())
        {
            Position tmp = q.front();
            q.pop();

            if (tmp.x <= 0 || tmp.x >= M || tmp.y <= 0 || tmp.y >= N) // boundaries
                continue;
            if (grid[tmp.x][tmp.y] || grid[tmp.x - 1][tmp.y] || grid[tmp.x][tmp.y - 1] || grid[tmp.x - 1][tmp.y - 1]) // obstacles
                continue;

            if (tmp.time < res[tmp.x][tmp.y]) // relax
                res[tmp.x][tmp.y] = tmp.time;
            if (tmp.ort == 0) // move
                for (int i = 3; i >= 1; --i)
                {
                    Position np(tmp.x + i, tmp.y, ort, tmp.time + 1);
                    q.push(np);
                }
            else if (tmp.ort == 1)
                for (int i = 3; i >= 1; --i)
                {
                    Position np(tmp.x, tmp.y + i, ort, tmp.time + 1);
                    q.push(np);
                }
            else if (tmp.ort == 2)
                for (int i = 3; i >= 1; --i)
                {
                    Position np(tmp.x - i, tmp.y, ort, tmp.time + 1);
                    q.push(np);
                }
            else
                for (int i = 3; i >= 1; --i)
                {
                    Position np(tmp.x, tmp.y - i, ort, tmp.time + 1);
                    q.push(np);
                }
            Position np1(tmp.x, tmp.y, (ort + 1) % 4, tmp.time + 1); // turn
            q.push(np1);
            Position np2(tmp.x, tmp.y, (ort - 1) % 4, tmp.time + 1);
            q.push(np2);
        }

        if (res[e1][e2] == INF)
            printf("-1\n");
        else
            printf("%d\n", res[e1][e2]);

        scanf("%d %d", &M, &N);
    }

    return 0;
}