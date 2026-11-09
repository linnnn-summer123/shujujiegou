//项目名称:简单的通讯录管理程序
//项目功能:实现通讯录的增删改查功能
#include <iostream>
#include <cstring>
using namespace std;

//定义联系人结构体
struct Contact
{
    char name[50];//联系人姓名
    char phone[12];//联系人电话
    struct Birthday//联系人生日
    {
        int year;//年
        int month;//月
        int day;//日
    }birthday;
    int age;//联系人年龄
};

//定义通讯录结点结构体
struct Node
{
    Contact data;//联系人信息
    Node* next;//指向下一个结点的指针
};

/*函数功能:初始化一个空的通讯录链表
*函数形参:无
*函数返回值:返回一个空的通讯录链表头指针,Node*类型
*/
Node* InitAddressBook()
{
    Node* head = new Node;
    if (head == NULL)
        cout << "内存分配失败!" << endl;
    else
        head->next = NULL;
    return head;
}

/*函数功能:采用头插法创建一个通讯录链表
*函数形参:通讯录链表头指针Node*head,联系人信息Contact data
*函数返回值:创建成功返回true,否则返回false,bool类型
*/
bool CreateAddressBookHead(Node* head, Contact data)
{
    Node* node = new Node;
    if (node == NULL)
    {
        cout << "内存分配失败!" << endl;
        return false;
    }
    node->data = data;
    node->next = head->next;
    head->next = node;
    return true;
}

/*函数功能:采用尾插法创建一个通讯录链表
*函数形参:通讯录链表头指针Node*head,联系人信息Contact data
*函数返回值:创建成功返回true,否则返回false,bool类型
*/
bool CreateAddressBookTail(Node* head, Contact data)
{
    static Node* tail = head;
    Node* node = new Node;
    if (node == NULL)
    {
        cout << "内存分配失败!" << endl;
        return false;
    }
    node->data = data;
    node->next = NULL;
    tail->next = node;
    tail = node;
    return true;
}

/*函数功能:输入单个联系人信息
*函数形参:无
*函数返回值:返回联系人信息,Contact类型
*/
Contact InputContact()
{
    Contact data;
    cout << "请输入联系人姓名:";
    cin >> data.name;
    cout << "请输入联系人电话:";
    cin >> data.phone;
    cout << "请输入联系人生日(年月日):";
    cin >> data.birthday.year >> data.birthday.month >> data.birthday.day;
    data.age = 2026 - data.birthday.year;
    return data;
}

/*函数功能:输出单个联系人信息
*函数形参:联系人信息Contact data
*函数返回值:无,void类型
*/
void OutputContact(Contact data)
{
    cout << "姓名:" << data.name << endl;
    cout << "电话:" << data.phone << endl;
    cout << "生日:" << data.birthday.year << "年" << data.birthday.month << "月" << data.birthday.day << "日" << endl;
    cout << "年龄:" << data.age << endl;
}

/*函数功能:输出通讯录中所有联系人信息
*函数形参:通讯录链表头指针Node*head
*函数返回值:无,void类型
*/
void OutputAddressBook(Node* head)
{
    Node* node = head->next;
    if (node == nullptr)
    {
        cout << "通讯录为空！" << endl;
        return;
    }
    while (node)
    {
        OutputContact(node->data);
        cout << "----------------------" << endl;
        node = node->next;
    }
}

/*函数功能:按姓名查找通讯录中指定联系人信息
*函数形参:通讯录链表头指针Node* head,联系人姓名char name[]
*函数返回值:查找成功,返回地址,否则返回空,Node*类型
*/
Node* SearchContactByName(Node* head, char* name)
{
    Node* node = head->next;
    while (node)
    {
        if (strcmp(node->data.name, name) == 0)
            return node;
        node = node->next;
    }
    return NULL;
}

/*函数功能:按电话查找通讯录中指定联系人信息
*函数形参:通讯录链表头指针Node*head,联系人电话char phone[]
*函数返回值:查找成功,返回地址,否则返回空,Node*类型
*/
Node* SearchContactByPhone(Node* head, char* phone)
{
    Node* node = head->next;
    while (node)
    {
        if (strcmp(node->data.phone, phone) == 0)
            return node;
        node = node->next;
    }
    return NULL;
}

/*函数功能:在指定联系人的后面插入一个新的联系人
*函数形参:通讯录链表头指针Node*head,指定联系人地址Node*target,联系人信息Contact data
*函数返回值:插入成功,返回true,否则返回false,bool类型
*/
bool InsertContactAfter(Node* head, Node* target, Contact data)
{
    if (target == nullptr)
        return false;
    Node* node = new Node;
    if (node)
    {
        node->data = data;
        node->next = target->next;
        target->next = node;
        return true;
    }
    return false;
}

/*函数功能:查找指定联系人的前驱结点
*函数形参:通讯录链表头指针Node*head,指定联系人地址Node*target
*函数返回值:查找成功,返回前驱,否则返回空,Node*类型
*/
Node* SearchPreNode(Node* head, Node* target)
{
    for (Node* pre = head;pre->next != NULL; pre = pre->next)
    {
        if (pre->next == target)
            return pre;
    }
    return NULL;
}

/*函数功能:在指定联系人的前面插入一个新的联系人
*函数形参:通讯录链表头指针Node*head,指定联系人地址Node*target,联系人信息Contact data
*函数返回值:插入成功,返回true,否则返回false,bool类型
*/
bool InsertContactBefore(Node* head, Node* target, Contact data)
{
    Node* pre = SearchPreNode(head, target);
    if (pre)
    {
        Node* node = new Node;
        if (node)
        {
            node->data = data;
            node->next = target;
            pre->next = node;
            return true;
        }
    }
    return false;
}

/*函数功能:删除指定联系人
*函数形参:通讯录链表头指针Node*head,指定联系人Node*target
*函数返回值:删除成功,返回true,否则返回false,bool类型
*/
bool DeleteContact(Node* head, Node* target)
{
    Node* pre = SearchPreNode(head, target);
    if (pre)
    {
        pre->next = target->next;
        delete target;
        return true;
    }
    return false;
}

/*函数功能:删除指定联系人的后继
*函数形参:通讯录链表头指针Node* head,指定联系人Node*target
*函数返回值:删除成功,返回true,否则返回false,bool类型
*/
bool DeleteContactNext(Node* head, Node* target)
{
    if (target->next)
    {
        Node* node = target->next;
        target->next = node->next;
        delete node;
        return true;
    }
    return false;
}

/*函数功能:修改联系人信息
*/
void ModifyContact(Node* target)
{
    cout << "请重新输入该联系人信息：" << endl;
    Contact newData = InputContact();
    target->data = newData;
    cout << "修改完成！" << endl;
}

/*函数功能:打印用户选择菜单
*函数形参:无
*函数返回值:返回用户的选择,int类型
*/
int PrintMenu()
{
    int choice;
    cout << "====通讯录管理程序====" << endl;
    cout << "1.添加联系人" << endl;
    cout << "2.删除联系人" << endl;
    cout << "3.查找联系人" << endl;
    cout << "4.修改联系人" << endl;
    cout << "5.显示所有联系人" << endl;
    cout << "6.退出程序" << endl;
    cout << "======================" << endl;
    cout << "请输入您的选择(1-6):";
    cin >> choice;
    return choice;
}

//释放整个链表内存
void FreeBook(Node* head)
{
    Node* p = head;
    while (p != nullptr)
    {
        Node* q = p;
        p = p->next;
        delete q;
    }
}

int main()
{
    Node* book = InitAddressBook();
    int select;
    char buf[50];
    while (true)
    {
        select = PrintMenu();
        if (select == 1)
        {
            Contact c = InputContact();
            CreateAddressBookTail(book, c);
            cout << "添加成功！" << endl;
        }
        else if (select == 2)
        {
            cout << "输入要删除的联系人姓名：";
            cin >> buf;
            Node* del = SearchContactByName(book, buf);
            if (del != nullptr)
            {
                DeleteContact(book, del);
                cout << "删除成功！" << endl;
            }
            else
                cout << "未找到该联系人" << endl;
        }
        else if (select == 3)
        {
            cout << "输入要查找的姓名：";
            cin >> buf;
            Node* res = SearchContactByName(book, buf);
            if (res)
                OutputContact(res->data);
            else
                cout << "没有找到联系人" << endl;
        }
        else if (select == 4)
        {
            cout << "输入要修改的联系人姓名：";
            cin >> buf;
            Node* res = SearchContactByName(book, buf);
            if (res)
                ModifyContact(res);
            else
                cout << "未找到联系人" << endl;
        }
        else if (select == 5)
        {
            OutputAddressBook(book);
        }
        else if (select == 6)
        {
            cout << "程序退出" << endl;
            FreeBook(book);
            break;
        }
        else
        {
            cout << "输入选项无效，请输入1~6" << endl;
        }
    }
    return 0;
}