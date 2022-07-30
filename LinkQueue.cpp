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

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct LinkQueue
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    if (!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;
    return OK;
}

Status IsEmpty_Q(LinkQueue Q)
{
    return Q.front == Q.rear ? TRUE : FALSE;
}

Status DestroyQueue(LinkQueue &Q)
{
    while (Q.front)
    {
        /* QNode *p=Q.front;
        Q.front=Q.front->next;
        delete p; */

        Q.rear = Q.front->next;
        delete Q.front;
        Q.front = Q.rear;
    }
    Q.rear = NULL;
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e)
{
    QueuePtr p = new QNode;
    if (!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return ERROR;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
    return OK;
}

Status GetHead(LinkQueue Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.front->next->data;
    return OK;
}