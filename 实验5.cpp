#include <iostream>
using namespace std;

typedef int DataType;

struct LinkStack
{
    DataType data;
    LinkStack* next;
};

LinkStack* InitStack()
{
    return nullptr;
}

bool IsEmpty(LinkStack* s)
{
    return s == nullptr;
}

bool Push(LinkStack** s, DataType val)
{
    LinkStack* newNode = new LinkStack;
    if (!newNode)
        return false;
    newNode->data = val;
    newNode->next = *s;
    *s = newNode;
    return true;
}

bool Pop(LinkStack** s, DataType& val)
{
    if (IsEmpty(*s))
        return false;
    LinkStack* p = *s;
    val = p->data;
    *s = (*s)->next;
    delete p;
    return true;
}

bool GetTop(LinkStack* s, DataType& val)
{
    if (IsEmpty(s))
        return false;
    val = s->data;
    return true;
}

void DestroyStack(LinkStack** s)
{
    LinkStack* p;
    while (*s)
    {
        p = *s;
        *s = (*s)->next;
        delete p;
    }
}

int main()
{
    LinkStack* st = InitStack();
    int v;
    Push(&st, 10);
    Push(&st, 20);
    GetTop(st, v);
    cout << "栈顶元素：" << v << endl;
    Pop(&st, v);
    cout << "出栈元素：" << v << endl;
    DestroyStack(&st);
    return 0;
}