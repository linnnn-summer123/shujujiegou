#include <iostream>
using namespace std;

typedef int DataType;
struct Stack
{
    int top;
    int maxsize;
    DataType* elements;
};

void InitStack(Stack& st, int max)
{
    st.maxsize = max;
    st.elements = new DataType[st.maxsize];
    st.top = -1;
}

bool IsEmpty(Stack& st)
{
    return st.top == -1;
}

bool Push(Stack& st, DataType x)
{
    st.top++;
    st.elements[st.top] = x;
    return true;
}

bool Pop(Stack& st, DataType& x)
{
    x = st.elements[st.top];
    st.top--;
    return true;
}

void Convert(int number, int base)
{
    Stack st;
    InitStack(st, 20);
    if (number == 0)
    {
        cout << "转换结果：0" << endl;
        return;
    }
    while (number > 0)
    {
        int rem = number % base;
        Push(st, rem);
        number = number / base;
    }
    cout << "转换结果：";
    int temp;
    while (!IsEmpty(st))
    {
        Pop(st, temp);
        cout << temp;
    }
    cout << endl;
    delete[] st.elements;
}

int main()
{
    cout << "=====进制转换测试=====" << endl;
    int num, b;
    cout << "输入十进制数：";
    cin >> num;
    cout << "输入目标进制(2~9)：";
    cin >> b;
    Convert(num, b);
    return 0;
}