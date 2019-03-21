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
    void Delete(T key);
private:
    SkewNode<T> *_Merge(SkewNode<T> *root_1, SkewNode<T> *root_2);
    void _Purge(SkewNode<T> *root);
};

template<class T, class CompareFunction>
CSkewHeap<T, CompareFunction>::CSkewHeap()
{
    root = nullptr;
}

template<class T, class CompareFunction>
CSkewHeap<T, CompareFunction>::~CSkewHeap()
{
    _Purge(root);
}

template<class T, class CompareFunction>
void CSkewHeap<T, CompareFunction>::_Purge(SkewNode<T> *root)
{

}

template<class T, class CompareFunction>
void CSkewHeap<T, CompareFunction>::Insert(T key)
{
    SkewNode newNode(key);
    _Merge(this->root, newNode);
}

template<class T, class CompareFunction>
void CSkewHeap<T, CompareFunction>::Delete(T key)
{
    
}


template<class T, class CompareFunction>
SkewNode<T> *CSkewHeap<T, CompareFunction>::_Merge(SkewNode<T> *root_1, SkewNode<T> *root_2)
{
    SkewNode<T> *firstRoot = root_1;
    SkewNode<T> *secondRoot = root_2;

    if (firstRoot == nullptr)
        return secondRoot;

    if (secondRoot == nullptr)
        return firstRoot;

    if(sh_compare->Less(firstRoot->key, secondRoot->key))
    {
        SkewNode<T>* tempHeap = firstRoot->rightNode;
        firstRoot->rightNode = firstRoot->leftNode;
        firstRoot->leftNode = _Merge(secondRoot, tempHeap);
        return firstRoot;
    }
    else
        return _Merge(secondRoot, firstRoot);
}

int main()
{

    return 0;
}