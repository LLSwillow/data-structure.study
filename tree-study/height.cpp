#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* GetNode(int x)
{
    Node* temp=new Node();
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
};
void Insert(Node* &root,int data)
{
    if(root==NULL)
    {
        root=GetNode(data);
    }
    else{
        (data<=root->data)?Insert(root->left,data):Insert(root->right,data);
    }
}
int Findheight(Node* root)
{
    if(root==NULL)return -1;//空树的高度为-1
    int leftheight=Findheight(root->left);
    int rightheight=Findheight(root->right);
    return max(leftheight,rightheight)+1;//由于这里递归之后max函数只计算到子树的高度，需要加上根节点到子树的这个链接
}
int main()
{
    Node* root=NULL;
    Insert(root,20);
    Insert(root,2);
    Insert(root,17);
    Insert(root,21);
    int height=Findheight(root);
    cout<<height;
    return 0;
}