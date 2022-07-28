#include <iostream>
using namespace std;

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef struct elemtype
{
    char name[20];
    char sex;
    int score;
} ElemType;

typedef struct Lnode
{
    ElemType data;
    struct Lnode *next;
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