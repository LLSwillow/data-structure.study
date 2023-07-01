#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
void Insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // 创建节点
    (*temp).data = x;
    temp->next = head;
    head = temp;
}
void Print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Delete(int x)
{
    struct Node *temp1 = head;
    if (x == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for (int i = 0; i < x - 2; i++)
    {
        temp1 = temp1->next;
    }                                 // 现在找到的时目标位置的前一个位置 即此时temp1表示的是要删除元素的前一个元素
    struct Node *temp2 = temp1->next; // 现在temp2表示的是要删除的这个元素
    temp1->next = temp2->next;        // 让n-1的地址指向n+1的位置
    free(temp2);
}
int main()
{
    head = NULL;
    // 由于链表初始为空，也就是从头部插入数据
    Insert(2);
    Insert(3);
    Insert(8);
    Insert(6);
    Insert(4);
    Print();
    int n; // n表示想要删除的元素的位置
    scanf("%d", &n);
    Delete(n);
    Print();
    return 0;
}