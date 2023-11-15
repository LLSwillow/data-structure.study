#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *getnew(int data)
{
    Node *newnode = new Node();
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
void Insert(Node *&root, int data)
{
    if (root == NULL)
    {
        root = getnew(data);
        // return root;
    }
    else{
        (data <= root->data) ? Insert(root->left, data) : Insert(root->right, data);
    }
}
int Findmin(Node *root)
{
    if (root == NULL)
        return -1;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int Findmax(Node* root)
{
    if(root==NULL)return -1;
    else if(root->right==NULL)return root->data;//右子树为空 作为递归出口
    return Findmax(root->right);
}
int main()
{
    Node *root = NULL;
    Insert(root, 200);
    Insert(root, 2);
    Insert(root, 20);
    Insert(root, 201);
    int Min = Findmin(root);
    int Max = Findmax(root);
    cout << Min << " " << Max;
    return 0;
}