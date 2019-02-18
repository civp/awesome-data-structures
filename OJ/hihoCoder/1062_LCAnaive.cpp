// Lowest Common Ancestor, WA?
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

int main()
{
    const std::string god = "OMyFGod";
    int N;
    scanf("%d", &N);
    std::unordered_map<std::string, std::string> parent;
    for (int i = 0; i < N; ++i)
    {
        std::string father, son;
        std::cin >> father >> son;
        parent[son] = father;
        if (parent.find(father) == parent.end())
            parent[father] == god; // Everyone has a father
    }
        
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i)
    {
        std::string a, b;
        std::cin >> a >> b;
        std::unordered_set<std::string> ancestors;
        while (parent.find(a) != parent.end())
        {
            ancestors.insert(a);
            a = parent[a];
        }
        bool isExist = false;
        while (parent.find(b) != parent.end())
        {
            if (ancestors.find(b) != ancestors.end())
            {
                isExist = true;
                break;
            }
            b = parent[b];
        }
        if (!isExist)
            printf("-1\n");
        else
            std::cout << b << std::endl;
    }
    return 0;
}