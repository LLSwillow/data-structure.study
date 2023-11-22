//不断递归判断根节点左右节点的值是否都符合二叉搜索树并判断其子树是否满足
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
bool IsSubtreeGreater(Node* root,int data)//检查root节点及以下有没有比data大的数
{
    if(root==NULL)return 1;
    else{
        if(root->data>=data && IsSubtreeGreater(root->left,data)
        && IsSubtreeGreater(root->right,data))
            return 1;
    }
    return 0;
}
bool IsSubtreelesser(Node* root,int data)//检查root节点及以下有没有比data小的数
{
    if(root==NULL)return 1;
    else{
        if(root->data<=data && IsSubtreelesser(root->left,data)
        && IsSubtreelesser(root->right,data))
            return 1;
    }
    return 0;
}
bool IsbinaryST(Node* root)//检查root这棵树是不是二叉搜索树
{
    if(root==NULL)return 1;
    else{//检查根节点的左/右子树中有没有比根节点大/小的数  同时检查其左右子树是否符合二叉搜索树的条件
        if(IsSubtreelesser(root->left,root->data) 
        && IsSubtreeGreater(root->right,root->data)
        && IsbinaryST(root->left) && IsbinaryST(root->right))
        return 1;
    }
    return 0;
}
int main()
{
    Node* root=NULL;
    Insert(root,7);  
    Insert(root,17);
    Insert(root,2);
    Insert(root,5);
    Insert(root,77);
    bool ans=IsbinaryST(root);
    cout<<ans;
    return 0;
}