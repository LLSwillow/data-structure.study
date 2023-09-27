#include<iostream>
#include<stack>
using namespace std;
struct Node
{
    char data;
    Node* link;
};
struct Node* top=NULL;
void Push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = x;
    temp->link = top;
    top = temp;
}
void Reverse()
{
    if(top==NULL)//空表
    {
        return;
    }
    stack<struct Node*> S;
    Node* temp=top;
    while(temp!=NULL){
        S.push(temp);
        temp=temp->link;
    }
    temp=S.top();
    top=temp;
    S.pop();
    while(!S.empty())
    {
        temp->link=S.top();
        S.pop();
        temp=temp->link;
    }
    temp->link = NULL;
}

int main()
{
    Push('q');
    Push('h');
    Push('5');
    Push('e');
    Reverse();
    while(top!=NULL)
    {
        cout<<top->data<<" ";
        top=top->link;
    }
    return 0;
}