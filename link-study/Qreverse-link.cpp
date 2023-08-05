#include <iostream>
using namespace std;
// 节点结构体
struct Node
{
    int data;
    Node *next;
};
struct Node *head;
// 从链表头部插入数据
void Insert(int x)
{
    Node *temp1 = new Node();
    temp1->data = x;
    // temp1->next=NULL;
    temp1->next = head;
    head = temp1;
}
void Reverse(struct Node *&head)
{
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next; // 记录当前节点的下一个节点的地址
        current->next = prev; // 将当前节点与前一个节点建立联系
        prev = current;       // 向后更新上一个节点
        current = next;       // 向后更新当前节点
    }
    head = prev;
}
void Print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    head = NULL;
    // 向链表中插入数据
    Insert(2);
    Insert(20);
    Insert(28);
    Insert(12);
    Insert(24);
    Print();
    Reverse(head);
    Print();
}