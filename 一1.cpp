#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct {
    int data[maxSize];
    int length;
} SqList;

void InitList(SqList *L) {
    L->length = 0;
}

void CreateList(SqList *L, int n) {
    if (n < 0 || n > maxSize) {
        printf("创建失败，长度非法\n");
        return;
    }
    printf("请输入%d个元素：", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &L->data[i]);
    }
    L->length = n;
}

int IsEmpty(SqList *L) {
    return L->length == 0;
}

int GetLength(SqList *L) {
    return L->length;
}

void PrintList(SqList *L) {
    if (IsEmpty(L)) {
        printf("顺序表为空！\n");
        return;
    }
    printf("顺序表元素：");
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int GetElem(SqList *L, int position, int *e) {
    if (position < 1 || position > L->length) {
        return 0;
    }
    *e = L->data[position - 1];
    return 1;
}

int SeqSearch(SqList *L, int value) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == value) {
            return i + 1;
        }
    }
    return 0;
}

int BinarySearch(SqList *L, int value) {
    int low = 0, high = L->length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (L->data[mid] == value) {
            return mid + 1;
        } else if (L->data[mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
}

int ListInsert(SqList *L, int position, int x) {
    if (position < 1 || position > L->length + 1) {
        printf("插入位置非法\n");
        return 0;
    }
    if (L->length >= maxSize) {
        printf("顺序表满，无法插入\n");
        return 0;
    }
    for (int i = L->length; i >= position; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[position - 1] = x;
    L->length++;
    return 1;
}

int ListDeletePos(SqList *L, int position, int *e) {
    if (position < 1 || position > L->length) {
        printf("删除位置非法\n");
        return 0;
    }
    *e = L->data[position - 1];
    for (int i = position - 1; i < L->length - 1; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
    return 1;
}

void ListDeleteAllValue(SqList *L, int value) {
    int i = 0;
    while (i < L->length) {
        if (L->data[i] == value) {
            for (int j = i; j < L->length - 1; j++) {
                L->data[j] = L->data[j + 1];
            }
            L->length--;
        } else {
            i++;
        }
    }
}

int main() {
    SqList L;
    InitList(&L);
    int n, op, pos, x, e, val, res;

    printf("请输入要创建顺序表元素个数：");
    scanf("%d", &n);
    CreateList(&L, n);

    while (1) {
        printf("\n====菜单====\n");
        printf("1.输出顺序表  2.判空  3.获取长度\n");
        printf("4.取pos元素  5.顺序查找 6.二分查找\n");
        printf("7.插入元素   8.删除pos元素 9.删除所有value 0.退出\n");
        printf("请选择操作：");
        scanf("%d", &op);
        if (op == 0) break;
        switch (op) {
            case 1: PrintList(&L); break;
            case 2:
                if (IsEmpty(&L)) printf("顺序表为空\n");
                else printf("顺序表非空\n");
                break;
            case 3: printf("顺序表长度=%d\n", GetLength(&L)); break;
            case 4:
                printf("输入position：");
                scanf("%d", &pos);
                if(GetElem(&L, pos, &e)) printf("第%d个元素=%d\n", pos, e);
                else printf("位置错误\n");
                break;
            case 5:
                printf("输入查找值：");
                scanf("%d", &val);
                res = SeqSearch(&L, val);
                if(res) printf("顺序查找：位置%d\n", res);
                else printf("未找到\n");
                break;
            case 6:
                printf("输入查找值：");
                scanf("%d", &val);
                res = BinarySearch(&L, val);
                if(res) printf("二分查找：位置%d\n", res);
                else printf("未找到（二分要求表有序）\n");
                break;
            case 7:
                printf("输入插入位置position，插入值x：");
                scanf("%d%d", &pos, &x);
                if(ListInsert(&L, pos, x)) printf("插入成功\n");
                break;
            case 8:
                printf("输入删除位置position：");
                scanf("%d", &pos);
                if(ListDeletePos(&L, pos, &e)) printf("删除元素=%d\n", e);
                break;
            case 9:
                printf("输入要删除的值value：");
                scanf("%d", &val);
                ListDeleteAllValue(&L, val);
                printf("已删除所有值为%d的元素\n", val);
                break;
        }
    }
    return 0;
}

