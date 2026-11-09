#include <iostream>
#include <cstring>
using namespace std;

typedef char DataType;

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

bool Push(LinkStack** s, DataType ch)
{
    LinkStack* newNode = new LinkStack;
    if (!newNode)
        return false;
    newNode->data = ch;
    newNode->next = *s;
    *s = newNode;
    return true;
}

bool Pop(LinkStack** s, DataType& ch)
{
    if (IsEmpty(*s))
        return false;
    LinkStack* p = *s;
    ch = p->data;
    *s = (*s)->next;
    delete p;
    return true;
}

bool IsBracketMatch(const char* str)
{
    LinkStack* st = InitStack();
    bool flag = true;
    char topCh;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[')
        {
            Push(&st, c);
        }
        else if (c == ')')
        {
            if (!Pop(&st, topCh) || topCh != '(')
            {
                flag = false;
                break;
            }
        }
        else if (c == '}')
        {
            if (!Pop(&st, topCh) || topCh != '{')
            {
                flag = false;
                break;
            }
        }
        else if (c == ']')
        {
            if (!Pop(&st, topCh) || topCh != '[')
            {
                flag = false;
                break;
            }
        }
    }
    if (flag && IsEmpty(st))
        return true;
    return false;
}

int main()
{
    char buf[100];
    cout << "请输入括号字符串：";
    cin >> buf;
    if (IsBracketMatch(buf))
        cout << "匹配" << endl;
    else
        cout << "不匹配" << endl;
    return 0;
}