#include <iostream>

// SkewNode
template<class T>
class SkewNode
{
public:
    T key;
    SkewNode<T> *leftNode;
    SkewNode<T> *rightNode;
    SkewNode(T key);
    ~SkewNode();
};

template<class T>
SkewNode<T>::SkewNode(T key)
{
    this->key = key;
    leftNode = rightNode = nullptr;
}

template<class T>
SkewNode<T>::~SkewNode() {}

// CSkewHeap
template<class T, class CompareFunction>
class CSkewHeap
{
public:
    SkewNode<T> *root;
    CSkewHeap();
    ~CSkewHeap();
    void Insert(T key);
    T PopMin();
    CSkewHeap &Union(CSkewHeap &sh);
private:
    SkewNode<T> *_Merge(SkewNode<T> *root_1, SkewNode<T> *root_2);
    // void _Purge(SkewNode<T> *root);
};

template<class T, class CompareFunction>
CSkewHeap<T, CompareFunction>::CSkewHeap()
{
    root = nullptr;
}

template<class T, class CompareFunction>
CSkewHeap<T, CompareFunction>::~CSkewHeap()
{
    // _Purge(root);
    while (root != nullptr)
        PopMin(root);
}

template<class T, class CompareFunction>
void CSkewHeap<T, CompareFunction>::Insert(T key)
{
    SkewNode<T> newNode(key);
    _Merge(this->root, newNode);
}

template<class T, class CompareFunction>
T CSkewHeap<T, CompareFunction>::PopMin()
{
    T minKey = root->key;
    SkewNode<T> *left = root->leftNode;
    SkewNode<T> *right = root->rightNode;
    delete root;
    _Merge(left, right);

    return minKey;
}

template<class T, class CompareFunction>
CSkewHeap<T, CompareFunction> &CSkewHeap<T, CompareFunction>::Union(CSkewHeap<T, CompareFunction> &sh)
{
    CSkewHeap<T, CompareFunction> newSkewHeap;
    newSkewHeap->root = _Merge(this->root, sh.root);
    return newSkewHeap;
}

// Recursive
template<class T, class CompareFunction>
SkewNode<T> *CSkewHeap<T, CompareFunction>::_Merge(SkewNode<T> *root_1, SkewNode<T> *root_2)
{
    SkewNode<T> *firstRoot = root_1;
    SkewNode<T> *secondRoot = root_2;

    if (firstRoot == nullptr)
        return secondRoot;

    if (secondRoot == nullptr)
        return firstRoot;

    if(CompareFunction.Less(firstRoot->key, secondRoot->key))
    {
        SkewNode<T>* tempHeap = firstRoot->rightNode;
        firstRoot->rightNode = firstRoot->leftNode;
        firstRoot->leftNode = _Merge(secondRoot, tempHeap);
        return firstRoot;
    }
    else
        return _Merge(secondRoot, firstRoot);
}

// template<class T, class CompareFunction>
// void CSkewHeap<T, CompareFunction>::_Purge(SkewNode<T> *root)
// {

// }

class IntegerCompare
{
public:
    bool Less(int a, int b)
    {
        return a < b;
    }
};

int main()
{
    CSkewHeap<int, IntegerCompare> sh1, sh2;
    sh1.Insert(1);
    sh1.Insert(3);
    sh1.Insert(5);
    sh2.Insert(7);
    sh2.Insert(2);
    CSkewHeap<int, IntegerCompare> sh = sh1.Union(sh2);
    std::cout << sh1.PopMin() << std::endl;

    return 0;
}