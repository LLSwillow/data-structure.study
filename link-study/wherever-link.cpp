// 在任意位置插入节点
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *head;
void Insert(int data, int n) // 要在第n个节点处插入数据，那么要找到第n-1个节点
// 但是当链表为空的时候，意味着我们无法在链表中找到要插入位置的前一个节点。所以得到思路分两种情况
{
    Node *temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node *temp2 = head;
    for (int i = 0; i < n - 2; i++) // 找到第n-1个节点
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void Print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    head = NULL; // 最初链表为空
    Insert(1, 1);
    Insert(2, 2);
    Insert(3, 1);
    Insert(4, 2);
    Print();
    return 0;
}