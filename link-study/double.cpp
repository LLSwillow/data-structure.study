#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head;
// 创建一个新的节点
struct Node *GetNew(int x)
{
    struct Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
// 从链表头部插入节点
void InsertAtHead(int x)
{
    struct Node *newnode = GetNew(x);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    // 更新地址指向来建立联系
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}
// 正向打印链表
void Print()
{
    struct Node *temp = head;
    printf("Forward:");
    if (temp == NULL)
        return;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// 反向打印
void ReversePrint()
{
    struct Node *temp = head;
    printf("Reverse:");
    if (temp == NULL)
        return;
    // 遍历链表到达最后一个节点
    while (temp->next != NULL) // 注意这里应该是判断temp->next不等于NULL，这样循环终止的时候，temp是指向最后一个节点的
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void Delete(int x)
{
    struct Node *temp = head;
    if (x == 1)
    {
        head = temp->next;
        free(temp);
    }
    // 在 for 循环中，temp 被移动到了要删除的节点
    // 但是在循环结束后，temp 没有进行任何检查，所以如果 x 大于链表的长度
    // 那么 temp 将会是一个空指针，这将导致程序崩溃

    // 由于我们传入的是 第 x 个节点，是个数字，所以for循环的主体要定义一个整型i来进行遍历
    for (int i = 0; i < x - 1; i++)
    {
        temp = temp->next;
    } // 找到了要删除的节点

    /*
    struct Node* temp1;
    temp1=temp->prev;
    temp->prev=temp->next;
    temp->next=temp1;
    free(temp1);
    */

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    // 释放要删除节点所占用的内存空间
}
void InsertAtTail(int x)
{
    struct Node *temp1 = GetNew(x);
    if (head == NULL)
    {
        head = temp1;
        return;
    }
    else
    {
        Node *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        } // 找到最后一个节点
        temp2->next = temp1;
        temp1->prev = temp2; // 记住我们这里双向链表节点有三个参数，注意赋值
    }
}
int main()
{
    // 起始链表为空
    head = NULL;
    InsertAtHead(1);
    Print();
    ReversePrint();
    InsertAtHead(5);
    Print();
    ReversePrint();
    InsertAtHead(9);
    InsertAtHead(4);
    Print();
    ReversePrint();
    // 删除节点函数 传入的数据应该是 第 几 个节点
    Delete(2);
    InsertAtTail(9);
    InsertAtTail(9);
    Print();
}