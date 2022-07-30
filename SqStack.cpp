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

typedef struct SqStack
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack &S)
{
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

Status IsEmpty_S(SqStack S)
{
    return S.top == S.base ? TRUE : FALSE;
}

Status GetLength_S(SqStack S)
{
    return S.top - S.base;
}

Status Clear_S(SqStack &S)
{
    S.top = S.base;
    return OK;
}

Status DestoryStack(SqStack &S)
{
    if (S.base)
        delete S.base;
    S.stacksize = 0;
    S.top = S.base = NULL;
    return OK;
}

Status Push_S(SqStack &S, SElemType e)
{
    if (S.top - S.base >= S.stacksize)
        return ERROR;
    *S.top++ = e;
    return OK;
}

Status Pop_S(SqStack &S, SElemType &e)
{
    if (S.top == S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}