//通过中序遍历判断是否有序(创建数组)来判断二叉搜索树
#include<iostream>
#include<vector>
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
bool Inorder(Node* root,vector<int> &A)
{
    if(root==NULL)return 1;
    if(!Inorder(root->left,A))return 0;//确定左子树为二叉搜索树
    if(!A.empty() && root->data<=A.back())return 0;//确定其是否有序
    A.push_back(root->data);
    return Inorder(root->right,A);//确定右子树是否是二叉搜索树
}
Node* previous=NULL;
bool IInorder(Node* root)
{
    if(root==NULL)return 1;
    if(!IInorder(root->left))return 0;
    if(previous!=NULL && previous->data>root->data)return 0;
    previous=root;
    return IInorder(root->right);
}
int main()
{
    Node* root=NULL;
    Insert(root,7);  
    Insert(root,17);
    Insert(root,2);
    Insert(root,5);
    Insert(root,77);
    vector<int> A;
    bool ans1=Inorder(root,A);
    bool ans2=IInorder(root);
    cout<<ans1;
    cout<<endl<<ans2;
    return 0;
}