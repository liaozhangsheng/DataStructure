#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef char TElemType;

typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

typedef struct BiThreeNode
{
    TElemType data;
    Status ltag, rtag;
    struct BiThreeNode *lchild, *rchild;
} BiThreeNode, *BiThreeTree;

void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        cout << T->data << " ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

Status CreatBiTree(BiTree &T)
{
    TElemType ch;
    cin >> ch;
    if (ch == '#')
    {
        T = NULL;
    }
    else
    {
        T = new BiNode;
        if (!T)
        {
            exit(OVERFLOW);
        }
        T->data = ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
    return OK;
}

Status Copy(BiTree T, BiTree &NewT)
{
    if (T = NULL)
    {
        NewT = NULL;
        return 0;
    }
    else
    {
        NewT = new BiNode;
        if (!NewT)
        {
            exit(OVERFLOW);
        }
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild, NewT->rchild);
    }
}

Status Depth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int left = Depth(T->lchild);
        int right = Depth(T->rchild);
        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
}

Status NodeCount(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    }
}

Status LeafCount(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        if (T->lchild == NULL && T->rchild == NULL)
        {
            return 1;
        }
        else
        {
            return LeafCount(T->lchild) + LeafCount(T->rchild);
        }
    }
}

