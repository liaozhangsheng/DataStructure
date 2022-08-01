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

typedef char SElemType;

typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

Status InitStack(LinkStack &S)
{
    if (!S)
        exit(OVERFLOW);
    S = NULL;
    return OK;
}

Status IsEmpty_L(LinkStack S)
{
    return S ? FALSE : TRUE;
}

Status Push_L(LinkStack &S, SElemType e)
{
    LinkStack p = new StackNode;
    if (!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

Status Pop_L(LinkStack &S, SElemType &e)
{
    if (!S)
        exit(INFEASIBLE);
    e = S->data;
    LinkStack p = S;
    S = S->next;
    delete p;
    return OK;
}

Status GetTop_L(LinkStack S, SElemType &e)
{
    if (!S)
        exit(INFEASIBLE);
    e = S->data;
    return OK;
}

int main(int argc, char const *argv[])
{
    return 0;
}
