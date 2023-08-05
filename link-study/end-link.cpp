#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *head;
void Insert(int x)
{
    //创建该节点
    struct Node *temp1 = new Node();
    temp1->data = x;
    temp1->next = NULL;
    //如果链表为空，直接更新即可。如果不单独把链表为空的情况做特殊处理，访问地址会崩溃(非法)
    if (head == NULL)
        head = temp1;
    else
    {
        //创建一个新的节点，遍历链表中的节点直到找到下一个地址为空的节点为止
        Node *temp2 = head;
        while (temp2->next != NULL)
            temp2 = temp2->next;
        //更新 插入的节点
        temp2->next = temp1;
    }
}
void Print()
{
    Node *temp = head;
    if (temp == NULL)
        return;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    head = NULL;
    Insert(2);
    Insert(6);
    Insert(7);
    Print();
    return 0;
}