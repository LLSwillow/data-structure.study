//广度优先--树的层次遍历
#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* GetNewNode(int data)
{
    Node* newNode=new Node();
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}
Node* Insert(Node* root,int data)
{
    if(root==NULL)
    {
        root=GetNewNode(data);
    }
    else if(data>root->data)
    {
        root->right=Insert(root->right,data);
    }
    else{
        root->left=Insert(root->left,data);
    }
    return root;
}
void breadthprint(Node* root)
{
    if(root==NULL)return;
    queue<Node*> Q;
    Q.push(root);//先把根节点放到队列里
    while(!Q.empty())
    {
        Node* current=Q.front();//存储当前队列中的第一个元素
        cout<<current->data<<" ";
        if(current->left!=NULL)Q.push(current->left);
        if(current->right!=NULL)Q.push(current->right);
        Q.pop();//队首元素已经打印过了出队
    }
}
int main()
{
    Node* root = NULL;
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
    breadthprint(root);
    return 0;
}