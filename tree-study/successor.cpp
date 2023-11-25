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
    if(root==NULL)root=Getnode(data);
    else{
        data>root->data?Insert(root->right,data):Insert(root->left,data);
    }
}
Node* Find(Node* root,int data)
{
    if(root==NULL)return NULL;
    else if(root->data==data)return root;
    else if(data<root->data)return Find(root->left,data);
    else return Find(root->right,data);
}
Node* Findmin(Node* root)
{
    if(root==NULL)return NULL;
    while(root->left!=NULL)root=root->left;
    return root;
}
Node* Getsuccessor(Node* root,int data)
{
    Node* current=Find(root,data);
    if(current==NULL)return NULL;
    if(current->right!=NULL){//该节点有右子树，那么其中序后继节点就是其右子树中最左的节点
        return Findmin(current->right);
    }
    else{//该节点没有右子树
        Node* successor=NULL;
        Node* ancestor=root;
        while(ancestor!=current)
        {
            if(current->data<ancestor->data){//说明该节点是其父节点的左孩子
                successor=ancestor;//暂时赋值为中序后继节点
                ancestor=ancestor->left;//不断更新以找到比它大的最小的祖先节点
            }
            else{//该节点为其父节点的右孩子
                ancestor=ancestor->right;//我们要向右找
            }
        }
        return successor;
    }
}
int main()
{
    Node* root=NULL;
    Insert(root,20);
    Insert(root,200);
    Insert(root,12);
    Insert(root,2);
    Insert(root,7);
    Insert(root,22);
    Insert(root,30);
    Insert(root,5);
    Insert(root,500);
    Node* successor=Getsuccessor(root,2);
    if(successor==NULL)cout<<"No successor Found\n";
    else cout<<successor->data;
    return 0;
}