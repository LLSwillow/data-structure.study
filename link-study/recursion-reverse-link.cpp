#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *head;
// 在链表末尾插入节点
void Insert(int x)
{
    struct Node *temp1 = new Node();
    temp1->data = x;
    temp1->next = NULL;
    if (head == NULL)
        head = temp1;
    else
    {
        Node *temp2 = head;
        while (temp2->next != NULL)
            temp2 = temp2->next;
        temp2->next = temp1;
    }
}
// 递归反转
void Reverse(struct Node *p)
{
    // 首先就是考虑递归出口。当 当前节点的下一个节点为NULL的时候，说明链表只有一个节点，直接赋值return即可
    if (p->next == NULL)
    {
        head = p; // 这是最后一个递归，我们把head改成了p:最后一个节点成了新链表的头节点
        return;
    }
    // 如果链表中不止一个节点，那么执行递归
    Reverse(p->next);
    // 当最后一个递归执行完之后，会接着执行倒数第二个递归中 递归之后的程序，也就是现在这个位置。后面的以此类推
    /*
        创建新节点存储当前节点(倒数第二个)的下一位节点(其实也就是最后一个节点，也就是在新链表中的第一个节点)
        Node *q = p->next;//建立联系
        q->next = p;//将原链表中的 需要递归的下一个节点 更新为当前节点
    */
    p->next->next = p; // 新链表中建立联系
    p->next = NULL;    // 原链表切断联系
}
void Print(struct Node *temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << " ";
    Print(temp->next);
}
int main()
{
    head = NULL;
    Insert(3);
    Insert(5);
    Insert(9);
    Insert(0);
    Reverse(head);
    Print(head);
    return 0;
}