//深度优先
#include <iostream>
using namespace std;
struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};
bstNode *Getnode(int data)
{
    bstNode *temp = new bstNode();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void Insert(bstNode *&root, int data)
{
    if (root == NULL)
    {
        root = Getnode(data);
    }
    else
    {
        (data <= root->data) ? Insert(root->left, data) : Insert(root->right, data);
    }
}
//先序
void Preorder(bstNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}
//中序
void Inorder(bstNode *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}
//后序
void Postorder(bstNode *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}
int main()
{
    bstNode *root = NULL; // 起始为空树
    Insert(root, 5);
    Insert(root, 15);
    Insert(root, 50);
    Insert(root, 2);
    Insert(root, 6);
    Insert(root, 10);
    Preorder(root);
    cout << endl;
    Inorder(root);
    cout << endl;
    Postorder(root);
    return 0;
}