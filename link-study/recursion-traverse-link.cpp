#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
struct Node* head;
void Insert(int situation,int data)
{
    struct Node* temp1=new Node();
    temp1->data=data;
    temp1->next=NULL;
    if(situation==1)
    {
        temp1->next=head;
        head=temp1;
        return;
    }
    struct Node* temp2=head;
    for(int i=0;i<situation-2;i++)
    {
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}
//传统迭代写法
void Print1()
{
    //遍历
    struct Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//正向递归打印链表
void Print2(struct Node* temp)
{
    //一定要判断链表是否为空，这是递归的出口！！
    if(temp==NULL)return;

    cout<<temp->data<<" ";
    Print2(temp->next);
    //cout<<endl;
}
//反向递归打印链表(这里只是逆序打印，并没有真正的反转链表)
void Print3(struct Node* temp)
{
    if(temp==NULL)return ;
    
    Print3(temp->next);
    cout<<temp->data<<" ";
}
/*
void Print3(struct Node* temp)
{
    while(temp!=NULL)
    {
        Print3(temp->next);
        cout<<temp->data<<" ";
    }
}*/

int main()
{
    head=NULL;
    Insert(1,2);
    Insert(2,5);
    Insert(3,9);
    Print1();
    Print2(head);
    cout<<endl;
    Print3(head);
    return 0;
}