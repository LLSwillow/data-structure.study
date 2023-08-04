#include <iostream>
using namespace std;
// 创建节点结构体
struct Node
{
    int data;
    struct Node *next;
};
// 从头部插入数据
struct Node *Insert(struct Node *head, int x)
{
    struct Node *newnode = new Node();
    newnode->data = x;
    newnode->next = head;
    head = newnode;
    return head;
}
// 反转函数
struct Node *Reverse(struct Node *head)
{
    //       上一个节点  当前节点  下一个节点
    struct Node *prev, *current, *next;
    current = head; // 当前节点初始为头节点
    prev = NULL;    // 头节点的上一个节点是null
    while (current != NULL)
    {
        next = current->next; // 先记录下下一个节点的地址，避免丢失
        current->next = prev; // 将当前节点的地址位更改为前一个节点，达成链接
        prev = current;       // 将 前一个节点 往后更新一位
        current = next;       // 将 当前节点 往后更新一位
    }
    head = prev; // 将head更新为反转后的链表
    return head;
}
// 打印函数
void Print(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
int main()
{
    // 创建头节点 (局部变量)
    struct Node *head;
    // 插入数据
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    Print(head);
    Print(Reverse(head));
    return 0;
}