#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *top = NULL;
// 从头部插入：即入栈
void Push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = x;
    temp->link = top;
    top = temp;
}
// 从头部删除数据
void Pop()
{
    struct Node *temp;
    if (top == NULL)
        return;
    temp = top;
    top = top->link;
    free(temp);
}
// 对于链表来说是正向打印，但是对于栈来说是逆序
void Print()
{
    printf("Stack:");
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
// 通过递归正序打印
void Print(struct Node *temp)
{
    if (temp == NULL) // 退出条件
    {
        return;
    }
    else
    {
        Print(temp->link);         // 递归调用
        printf("%d ", temp->data); // 打印元素
    }
}

int main()
{
    Push(2);
    Print();
    // Print(top);
    Push(5);
    Print();
    // Print(top);
    Push(10);
    Print();
    // Print(top);
    Pop();
    Print();
    // Print(top);
    Push(12);
    Print();
    // Print(top);
    return 0;
}