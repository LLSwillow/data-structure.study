//不断更改每个节点的数据范围看是否符合
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* Getnode(int data)
{
    Node* newnode=new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void Insert(Node* &root,int data)
{
    if(root==NULL)root=Getnode(data);
    else{
        (data<=root->data)?Insert(root->left,data):Insert(root->right,data);
    }
}
bool IsBstUtil(Node* root,int minV,int maxV)
{
    if(root==NULL)return 1;
    else{
        if(root->data>minV && root->data<maxV
        && IsBstUtil(root->left,minV,root->data)
        && IsBstUtil(root->right,root->data,maxV))
            return 1;
    }
    return 0;
}
bool IsbinarySearchTree(Node* root)
{
    return IsBstUtil(root,INT_MIN,INT_MAX);//传递数据上下限
}
int main()
{
    Node* root=NULL;
    Insert(root,7);  
    Insert(root,17);
    Insert(root,2);
    Insert(root,5);
    Insert(root,77);
    bool ans=IsbinarySearchTree(root);
    cout<<ans;
    return 0;
}