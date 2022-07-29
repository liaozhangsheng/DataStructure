#include<iostream>
#include<string>
using namespace std;

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef char ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status InitList_L(LinkList &L)
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

Status Length_L(LinkList L)
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

Status GetElem_L(LinkList L, Status i, ElemType &e)
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
    {
        return ERROR;
    }
    e = p->data;
    return OK;
}

/* LNode *LocateElem_L(LinkList L, ElemType e)
{
    LNode *p;
    p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
} */
Status LocateElem_L(LinkList L, ElemType e)
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

Status InsertElem_L(LinkList &L, Status i, ElemType e)
{
    LNode *p, *s;
    Status j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
    {
        return ERROR;
    }
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status DeleteElem_L(LinkList &L, Status i, ElemType &e)
{
    LNode *p, *q;
    Status j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!(p->next || j > i - 1))
    {
        return ERROR;
    }
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
    LNode *p,*r;
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

int main(int argc, char const *argv[])
{
    return 0;
}
