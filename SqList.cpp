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

typedef char ElemType;

typedef struct SqList
{
    ElemType *elem;
    int length;
} SqList;

Status InitList_Sq(SqList &L)
{
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem)
    {
        exit(OVERFLOW);
    }
    L.length = 0;
    return OK;
}

void DestoryList(SqList &L)
{
    if (L.elem)
        delete L.elem;
}

void ClearList(SqList &L)
{
    L.length = 0;
}

Status GetLength(SqList L)
{
    return L.length;
}

Status IsEmpty(SqList L)
{
    return L.length == 0 ? 1 : 0;
}

Status GetElem(SqList L, Status i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}

Status LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
            return i + 1;
    }
    return 0;
}

Status ListInsert_Sq(SqList &L, Status i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if (L.length == MAXSIZE)
        return ERROR;
    for (Status j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length++;
    return OK;
}

Status ListDelete_Sq(SqList &L, Status i, ElemType e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    for (int j = i; j <= L.length - 1; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return OK;
}

int main(int argc, char const *argv[])
{

    return 0;
}
