//使用引用
#include<iostream>
using namespace std;
struct bstNode{
    int data;
    bstNode* left;
    bstNode* right;
};
bstNode* Getnode(int data)
{
    bstNode* temp=new bstNode();
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void Insert(bstNode* &root,int data)
{
    if(root==NULL){
        root=Getnode(data);
    }
    else{
        (data<=root->data)?Insert(root->left,data):Insert(root->right,data);
    }
}
bool Search(bstNode* root,int x)
{
    if(root==NULL)return 0;
    else if(root->data==x){
        return 1;
    }
    else{
        return (x<=root->data)?Search(root->left,x):Search(root->right,x);
    }
}
int main()
{
    bstNode* root=NULL;//起始为空树
    Insert(root,5);
    Insert(root,15);
    Insert(root,50);
    Insert(root,2);
    Insert(root,6);
    Insert(root,10);
    //输入你想搜索的数据
    int x;
    cin>>x;
    bool ans=Search(root,x);
    cout<<ans;
    return 0;
}