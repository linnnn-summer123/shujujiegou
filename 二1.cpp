#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct Node
{
    DataType data;
    struct Node * next;
};

typedef struct Node Node;

Node* InitList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void HeadInsert(Node *head, DataType val)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = val;
    p->next = head->next;
    head->next = p;
}

void TailInsert(Node *head, DataType val)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    Node *cur = head;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = p;
}

int IsEmpty(Node *head)
{
    if(head->next == NULL)
        return 1;
    else
        return 0;
}

int GetLength(Node *head)
{
    int len = 0;
    Node *cur = head->next;
    while(cur != NULL)
    {
        len++;
        cur = cur->next;
    }
    return len;
}

void PrintList(Node *head)
{
    Node *cur = head->next;
    if(IsEmpty(head))
    {
        printf("链表为空\n");
        return;
    }
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    Node *L = InitList();
    TailInsert(L,10);
    TailInsert(L,20);
    TailInsert(L,30);
    printf("链表内容：");
    PrintList(L);
    printf("链表长度：%d\n",GetLength(L));
    printf("是否为空：%d（1空，0非空）\n",IsEmpty(L));

    HeadInsert(L,5);
    printf("头插5之后：");
    PrintList(L);
    printf("链表长度：%d\n",GetLength(L));
    return 0;

