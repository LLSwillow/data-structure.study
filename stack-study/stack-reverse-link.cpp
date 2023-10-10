#include <iostream>
#include <stack>
using namespace std;
// 节点
struct Node
{
    char data;
    Node *link;
};

// 建立链表 实现栈
struct Node *top = NULL;

void Push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = x;
    temp->link = top;

    top = temp;
}
void Reverse()
{
    if (top == NULL) // 空表
    {
        return;
    }
    stack<struct Node *> S; // 创建了一个 元素为节点类型 的栈
    Node *temp = top;
    // 从链表第一个元素开始 按顺序将元素入栈
    while (temp != NULL)
    {
        S.push(temp);
        temp = temp->link; // 最后一次循环将temp赋值为 链表的最后一个节点
    }
    temp = S.top(); // 这里将temp这个临时节点赋值为 栈顶的元素 即链表的最后一个元素

    top = temp; // 将链表的头节点 赋值为 链表的最后一个元素->反转的第一步  这样后面对temp之后结点的更改也就真实的改变了原链表的每个元素咯(值的覆盖
    S.pop();    // 反转的第一个节点出栈

    // 当栈不为空的时候，依次出栈，实现整个链表的反转
    while (!S.empty())
    {
        temp->link = S.top();
        S.pop();
        temp = temp->link;
    }
    temp->link = NULL;
}

int main()
{
    Push('q');
    Push('h');
    Push('5');
    Push('e');
    Reverse();
    while (top != NULL)
    {
        cout << top->data << " ";
        top = top->link;
    }
    return 0;
}