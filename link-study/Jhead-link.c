#include <stdio.h>
#include <stdlib.h>
// 创建链表
struct Node
{
    int data;          // 数据
    struct Node *next; // 指向链表中下一个数据的地址
};
struct Node *Insert(struct Node *head, int x)
{
    // 实现输入数据的插入
    /*错误代码 ：这个函数的问题在于它并没有真正地将新数据插入到链表中。
    它只是修改了传入的节点的数据域和指针域，而没有创建新的节点并将其插入到链表中。
    node->data = x;
    node->next = NULL;
    return node;
    */
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node)); // 创建一个新的节点
    newnode->data = x;
    newnode->next = head;
    head = newnode;
    return head;
}
/*
void Insert(Node** head,int x)//**这时改变的是本尊
{
    struct Node* temp = (Node*)malloc(sizeof(struct Node));temp->data= x;
    temp->next = NULL;
    if(*head != NULL) temp->next = *head;*head = temp;
}
*/
void Print(struct Node *node)
{
    // 打印链表中的数据
    printf("link is: ");
    // 不只有一个数据 所以需要通过循环打印出此时存在的所有数据 printf("%d ",node->data);
    while (node != NULL) // 循环条件是当下一个节点为空时表明此时数据已经打印完毕
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main()
{
    // 这个head并不是结构体内部的指针,是node型结构体の指针 我们不需要在main中对结构体内部的链接字段进行操作
    struct Node *head = NULL; // 链表初始状态是空的 没有数据

    // 接下来要提示用户想要链表中输入几个数据
    printf("How many numbers?\n");
    int count, i, x; // count表示总数 目的是通过count跳出循环，i用来执行循环，x用来表示每次插入的数据
    scanf("%d", &count);
    while (count--)
    {
        // 提示用户输入数据
        printf("Enter the number:\n");
        scanf("%d", &x);
        head = Insert(head, x);
        Print(head);
    }
}