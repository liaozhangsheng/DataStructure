#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;

typedef char QElemType;

typedef struct SqQueue
{
    QElemType *base;
    Status front, rear;
} SqQueue;

Status InitQueue(SqQueue &Q)
{
    Q.base = new QElemType[MAXSIZE];
    if (!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}

Status IsEmpty_Q(SqQueue Q)
{
    return Q.front == Q.rear ? TRUE : FALSE;
}

Status Length_Q(SqQueue Q)
{
    return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}

Status EnQueue(SqQueue &Q, QElemType e)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
    if (Q.front = Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}

QElemType GetHead(SqQueue Q)
{
    if(Q.front != Q.rear)
        return Q.base[Q.front];
}

int main(int argc, char const *argv[])
{
    return 0;
}
