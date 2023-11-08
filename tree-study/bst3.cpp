//不使用递归实现
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* Getnode(int data)
{
    Node* temp=new Node();
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void Insert(Node* &root,int data)
{
    if(root==NULL)
    {
        root=Getnode(data);
    }
    Node* temp=root;
    Node* parent=NULL;
    //temp用来找到往哪个子树上插
    while(temp)
    {
        parent=temp;//存储该节点的双亲结点
        temp=data<=temp->data?temp->left:temp->right;
    }
    if(data<=parent->data)parent->left=Getnode(data);
    else parent->right=Getnode(data);
}
bool Search(Node* root,int x)
{
    Node* temp=root;
    if(root->data==x)return 1;

    while(temp!=NULL && x!=temp->data)//只有当这两个条件有一个满足的时候才会退出循环 注意两个条件的顺序，要先检查是否为空
    {
        temp=x<=temp->data?temp->left:temp->right;
    }
    if(temp==NULL)return 0;
    return 1;
}
int main()
{
    Node* root=NULL;
    Insert(root,5);
    Insert(root,50);
    Insert(root,15);
    Insert(root,0);
    int x;
    cin>>x;
    bool ans=Search(root,x);
    cout<<ans;
    return 0;
}