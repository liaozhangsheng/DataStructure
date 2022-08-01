#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef char LElemType;

typedef struct LNode
{
    LElemType data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct DuLNode
{
    LElemType data;
    struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

Status InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    return OK;
}

Status IsEmpty_L(LinkList L)
{
    return (L->next == NULL) ? 1 : 0;
}

Status DestoryList_L(LinkList &L)
{
    LNode *p;
    while (L)
    {
        p = L;
        L->next;
        delete p;
    }
    return OK;
}

Status ClearList_L(LinkList &L)
{
    LNode *p, *q;
    p = L->next;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;
    return OK;
}

Status GetLength_L(LinkList L)
{
    LNode *p;
    Status length = 0;
    p = L->next;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

Status GetElem_L(LinkList L, Status i, LElemType &e)
{
    LNode *p;
    Status j = 1;
    p = L->next;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

/* LNode *LocateElem_L(LinkList L, LElemType e)
{
    LNode *p;
    p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
} */
Status LocateElem_L(LinkList L, LElemType e)
{
    LNode *p;
    Status j = 1;
    while (p && p->data != e)
    {
        p = p->next;
        j++;
    }
    if (p)
        return j;
    else
        return 0;
}

Status InsertElem_L(LinkList &L, Status i, LElemType e)
{
    LNode *p, *s;
    Status j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        return ERROR;
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status DeleteElem_L(LinkList &L, Status i, LElemType &e)
{
    LNode *p, *q;
    Status j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!(p->next || j > i - 1))
        return ERROR;
    q = p->next;
    p->next = q->next;
    e = p->data;
    delete q;
    return OK;
}

void CreatList_H(LinkList &L, Status n)
{
    L = new LNode;
    LNode *p;
    L->next = NULL;
    for (Status i = n; i < 0; --i)
    {
        p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

void CreateList_R(LinkList &L, Status n)
{
    L = new LNode;
    LNode *p, *r;
    L->next = NULL;
    r = L;
    for (int i = 0; i < n; ++i)
    {
        p = new LNode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

//循环链表连接
LinkList Connect(LinkList Ta, LinkList Tb)
{
    LNode *p;
    p = Ta->next;
    Ta->next = Tb->next->next;
    delete Tb->next;
    Tb->next = p;
    return Tb;
}

//双向链表
DuLinkList GetElem_DuL(DuLinkList &L, Status i)
{
    DuLNode *p;
    Status j = 1;
    p = L->next;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
    {
        return ERROR;
    }
    return p;
}

Status ListInsert_DuL(DuLinkList &L, Status i, LElemType e)
{
    DuLNode *s, *p;
    if (!(p = GetElem_DuL(L, i)))
    {
        return ERROR;
    }
    s = new DuLNode;
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

Status DeleteElem_DuL(DuLinkList &L, Status i, LElemType &e)
{
    DuLNode *p;
    if (!(p = GetElem_DuL(L, i)))
    {
        return ERROR;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    e = p->data;
    delete p;
    return OK;
}

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    LNode *pa, *pb, *pc;
    pa = La->next;
    pb = Lb->next;
    pc = Lc = La;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    delete Lb;
}

int main(int argc, char const *argv[])
{
    return 0;
}