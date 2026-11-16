#include <iostream>
using namespace std;

typedef int Datatype;
struct Node
{
    Datatype data;
    Node* next;
};
struct LinkQueue
{
    Node* front;
    Node* rear;
};

void InitLinkQueue(LinkQueue& q)
{
    q.front = new Node;
    q.front->next = nullptr;
    q.rear = q.front;
}

bool IsEmptyLink(LinkQueue& q)
{
    return q.front == q.rear;
}

void EnLinkQueue(LinkQueue& q, Datatype x)
{
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    q.rear->next = p;
    q.rear = p;
}

bool DeLinkQueue(LinkQueue& q, Datatype& x)
{
    if (IsEmptyLink(q))
    {
        cout << "链队列为空，出队失败" << endl;
        return false;
    }
    Node* p = q.front->next;
    x = p->data;
    q.front->next = p->next;
    if (q.rear == p)
        q.rear = q.front;
    delete p;
    return true;
}

bool GetFrontLink(LinkQueue& q, Datatype& x)
{
    if (IsEmptyLink(q))
    {
        cout << "链队列为空" << endl;
        return false;
    }
    x = q.front->next->data;
    return true;
}

void DestroyLinkQueue(LinkQueue& q)
{
    Node* p = q.front, * s;
    while (p != nullptr)
    {
        s = p;
        p = p->next;
        delete s;
    }
    q.front = q.rear = nullptr;
}

int main()
{
    LinkQueue q;
    InitLinkQueue(q);
    EnLinkQueue(q, 100);
    EnLinkQueue(q, 200);
    int val;
    GetFrontLink(q, val);
    cout << "队首：" << val << endl;
    DeLinkQueue(q, val);
    cout << "出队：" << val << endl;
    DestroyLinkQueue(q);
    return 0;
}