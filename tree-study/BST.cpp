//递归实现二叉搜索树
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
//创建新节点
Node* GetNewNode(int data)
{
    Node* newNode=new Node();
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}
//插入节点
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
bool Search(Node* root,int num)
{
    if(root == NULL) {
		return false;
	}
	else if(root->data == num) {
		return true;
	}
	else if(num <= root->data) {
		return Search(root->left,num);
	}
	else {
		return Search(root->right,num);
	}
}
int main()
{
    //创建一个树根，这里作为局部变量
    Node* root = NULL;
	//向树中插入数据
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	//输入想查找的数据
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;

	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
    return 0;
}