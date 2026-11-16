#include <iostream>
using namespace std;

typedef int Datatype;
struct SeqQueue
{
    int front;
    int rear;
    int maxsize;
    Datatype* elements;
};

void InitSeqQueue(SeqQueue& q, int size)
{
    q.maxsize = size + 1;
    q.elements = new Datatype[q.maxsize];
    q.front = 0;
    q.rear = 0;
}

bool IsEmptySeq(SeqQueue& q)
{
    return q.front == q.rear;
}

bool IsFullSeq(SeqQueue& q)
{
    return (q.rear + 1) % q.maxsize == q.front;
}

bool EnSeqQueue(SeqQueue& q, Datatype x)
{
    if (IsFullSeq(q))
    {
        cout << "队列满，入队失败" << endl;
        return false;
    }
    q.elements[q.rear] = x;
    q.rear = (q.rear + 1) % q.maxsize;
    return true;
}

bool DeSeqQueue(SeqQueue& q, Datatype& x)
{
    if (IsEmptySeq(q))
    {
        cout << "队列空，出队失败" << endl;
        return false;
    }
    x = q.elements[q.front];
    q.front = (q.front + 1) % q.maxsize;
    return true;
}

bool GetFrontSeq(SeqQueue& q, Datatype& x)
{
    if (IsEmptySeq(q))
    {
        cout << "队列为空，无队首" << endl;
        return false;
    }
    x = q.elements[q.front];
    return true;
}

void DestroySeqQueue(SeqQueue& q)
{
    delete[] q.elements;
    q.elements = nullptr;
    q.front = q.rear = 0;
    q.maxsize = 0;
}

int main()
{
    SeqQueue q;
    InitSeqQueue(q, 5);
    EnSeqQueue(q, 10);
    EnSeqQueue(q, 20);
    Datatype val;
    GetFrontSeq(q, val);
    cout << "队首：" << val << endl;
    DeSeqQueue(q, val);
    cout << "出队元素：" << val << endl;
    DestroySeqQueue(q);
    return 0;
}