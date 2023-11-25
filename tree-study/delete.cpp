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
Node* Findmin(Node* root)
{
    if(root==NULL)return root;
    else{
        if(root->left==NULL)return root;
        else{
            return Findmin(root->left);
        }
    }
}
Node* Delete(Node* &root,int data)
{
    if(root==NULL)return root;
    else{
        if(data>root->data)root->right=Delete(root->right,data);
        else if(data<root->data)root->left=Delete(root->left,data);
        else{//当要删除的数据=此时的root->data
            if(root->left==NULL && root->right==NULL){
                delete root;
                root=NULL;
            }
            else if(root->left==NULL){
                Node* temp=root;
                root=root->right;
                delete temp;
            }
            else if(root->right==NULL){
                Node* temp=root;
                root=root->left;
                delete temp;
            }
            else{
                Node* temp=Findmin(root->right);//找到右子树的最小值
                root->data=temp->data;
                root->right=Delete(root->right,temp->data);
            }
        }
    }
    return root;
}
void Inorder(Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
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
    root=Delete(root,5);
    root=Delete(root,12);
    root=Delete(root,200);
    Inorder(root);
    return 0;
}