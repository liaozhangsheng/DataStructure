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
        exit(OVERFLOW);
    L.length = 0;
    return OK;
}

void DestoryList_Sq(SqList &L)
{
    if (L.elem)
        delete L.elem;
}

void ClearList_Sq(SqList &L)
{
    L.length = 0;
}

Status GetLength_Sq(SqList L)
{
    return L.length;
}

Status IsEmpty_Sq(SqList L)
{
    return L.length == 0 ? 1 : 0;
}

Status GetElem_Sq(SqList L, Status i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}

Status LocateElem_Sq(SqList L, ElemType e)
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

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
    ElemType *pa, *pb, *pc, *pa_last, *pb_last, *pc_last;
    pa = La.elem;
    pb = Lb.elem;
    Lc.length = La.length + Lb.length;
    Lc.elem = new ElemType[Lc.length];
    pc = Lc.elem;
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last)
    {
        if (*pa <= *pb)
        {
            *pc = *pa;
            pa++;
        }
        else
        {
            *pc = *pb;
            pb++;
        }
        pc++;
    }
    while (pa <= pa_last)
    {
        *pc = *pa;
        pa++;
        pc++;
    }
    while (pb <= pb_last)
    {
        *pc = *pb;
        pb++;
        pc++;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
