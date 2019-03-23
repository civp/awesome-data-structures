#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *Leftist;
struct TreeNode
{
    int key;
    Leftist left;
    Leftist right;
    int npl; // null path length
};

Leftist MergeRec(Leftist h1, Leftist h2);
Leftist Merge(Leftist h1, Leftist h2);
int DeleteMin(Leftist *h);
Leftist Insert(Leftist h, int key);
void Purge(Leftist h);

Leftist MergeRec(Leftist h1, Leftist h2) // Recursive merge
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;
    if (h1->key < h2->key)
        return Merge(h1, h2);
    else
        return Merge(h2, h1);
}

Leftist Merge(Leftist h1, Leftist h2) // assume h1->key < h2->key
{
    if (h1->left == NULL) // single h1
        h1->left = h2;
    else
    {
        h1->right = MergeRec(h1->right, h2);
        if (h1->left->npl < h1->right->npl)
        {
            Leftist tmp = h1->left;
            h1->left = h1->right;
            h1->right = tmp;
        }
        h1->npl = h1->right->npl + 1; // min{npl(C) + 1}
    }
    return h1;  
}

Leftist MergeIter(Leftist h1, Leftist h2)
{
    // sort right path
    // swap children if necessary
}

int DeleteMin(Leftist *h)
{
    int ret = (*h)->key;
    Leftist l = (*h)->left, r = (*h)->right;
    free(*h);
    *h = MergeRec(l, r);
    return ret;
}

Leftist Insert(Leftist h, int key)
{
    Leftist h1 = malloc(sizeof(struct TreeNode));
    h1->key = key;
    h1->left = h1->right = NULL;
    h1->npl = 0;
    return MergeRec(h, h1);
}

void Purge(Leftist h)
{
    while (h)
        DeleteMin(&h);
}

int main()
{
    Leftist h = NULL;
    h = Insert(h, 1); // no dummy head
    h = Insert(h, 15);
    h = Insert(h, 33);
    h = Insert(h, 24);
    h = Insert(h, 7);
    h = Insert(h, 41);
    h = Insert(h, 0);
    printf("%d\n", DeleteMin(&h));
    printf("%d\n", DeleteMin(&h));
    printf("%d\n", DeleteMin(&h));
    printf("%d\n", DeleteMin(&h));
    Purge(h);
    
    return 0;
}