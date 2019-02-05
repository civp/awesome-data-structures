#ifndef KD_TREE
#define KD_TREE

#include <vector>

class KDTree
{
public:
    void KDTree(std::vector<std::vector<int>> v);
    int findNearestNeighrbor(int x);
private:
    PtrToNode KDT;
};

typedef struct KDTreeNode *PtrToNode;
struct KDTreeNode
{
    PtrToNode left;
    PtrToNode right;
};

#endif