// 将root定义为全局变量
#include <iostream>
using namespace std;
struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};
struct bstNode *root = NULL;
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
        data <= root->data ? Insert(root->left, data) : Insert(root->right, data);
    }
}
bool Search(bstNode *root, int x)
{
    if (root == NULL)
        return 0;
    else if (root->data == x)
        return 1;
    return x <= root->data ? Search(root->left, x) : Search(root->right, x);
}
int main()
{
    Insert(root, 1);
    Insert(root, 10);
    Insert(root, 0);
    Insert(root, -1);
    int x;
    cin >> x;
    bool ans = Search(root, x);
    cout << ans;
    return 0;
}