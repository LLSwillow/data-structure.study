#include <iostream>
#include <cstdlib>

using namespace std;

int m, x, k;
struct Node
{
    int data;
    Node *next;
};
struct Node *head;
// 在任意位置插入节点
void Insert(int x, int data)
{
    // 创建节点
    struct Node *temp1 = new Node();
    (*temp1).data = data;
    temp1->next = NULL;

    if (x == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    struct Node *temp2 = head;
    for (int i = 1; i < x - 1; i++)
    {
        temp2 = temp2->next;
    }
    /*这里刚开始写错了
    temp2->next=temp1;
    temp1->next=temp2->next;
    如果我们先执行temp2->next=temp1;，那么temp2->next的原始值就会丢失。
    这意味着当我们执行temp1->next=temp2->next;时，temp1->next实际上指向的是它自己，而不是原来temp2->next指向的节点。
    这样，新节点就没有被正确地插入到链表中。
    */
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void Delete(int x)
{
    struct Node *temp1 = head;
    /*我们原来的删除函数中，是有对删除头节点的单独处理的，在这里我们把这个写在了主函数中
     那么默认调用到Delete函数的是实现 除了头节点之外的其他任何节点的删除
    if (x == 1)
    {
        head = temp1->next;
        //free(temp1);
        return;
    }
    */
    int i = 0;
    for (int i = 1; i < x - 1; i++)
    {
        temp1 = temp1->next;
    }
    struct Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2); // 删除结点的释放，题目里并没有明确要求 或许可以不写？？
}
void Print()
{
    struct Node *temp1 = head;
    while (temp1 != NULL)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    cout << endl;
}
int main()
{
    cin >> m;
    while (m--)
    {
        char c;
        cin >> c;
        if (c == 'H')
        {
            cin >> x;
            // 如果是从头部插入节点，那么插入位置也就是1咯，这样写一个在任意位置插入节点就可以解决两种插入问题 省事
            Insert(1, x);
        }
        else if (c == 'D')
        {
            cin >> k;
            // 由于传入的数据是K-1，如果K=0会传过去复数，所以把K==0的情况单独写出来
            if (k == 0)
            {
                Node *temp1 = head;
                temp1 = head->next;
                head = temp1;
            }
            else
            {
                Delete(k - 1);
            }
        }
        else
        {
            cin >> k >> x;
            Insert(k - 1, x);
        }
    }
    Print();
    return 0;
}