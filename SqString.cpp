#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 255

typedef int Status;

typedef char SElemType;

typedef struct SqString
{
    SElemType string[MAXSIZE + 1];
    Status length;
} SqString;

// BF算法
Status Index_BF(SqString S, SqString T)
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (S.string[i] == T.string[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return INFEASIBLE;
}

// KMP算法
Status Index_KMP(SqString S, SqString T)
{
    int i = 1, j = 1;
    int next[MAXSIZE + 1];
    next[1] = 0;
    while (j < T.length)
    {
        if (T.string[j] == T.string[next[j]])
            next[++j] = ++next[j - 1];
        else
            next[++j] = next[j - 1];
    }
    while (i <= S.length)
    {
        if (S.string[i] == T.string[j])
        {
            if (j == T.length)
                return i - T.length + 1;
            else
                i++;
            j++;
        }
        else if (j == 0)
            i++;
        else
            j = next[j];
    }
    return INFEASIBLE;
}

int main(int argc, char const *argv[])
{
    return 0;
}
