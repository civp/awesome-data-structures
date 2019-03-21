#include <iostream>
#include <cstdio>
#include <vector>
#include "kdtree.hpp"

int main()
{
    int N, D;
    scanf("%d %d", &D, &N); // Dimension and #Tests
    std::vector<std::vector<int>> initList(N);
    std::vector<int> tmp(D);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < D; ++j)
            scanf("%d", tmp[j]);
        initList.push_back(tmp);
    }
    
    KDTree kdt(initList);

}