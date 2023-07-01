//从头部插入节点
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;//定义为全局变量 (或者定义为局部变量，在代码实现上会存在差异)
//插入函数
void Insert(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));//malloc 的返回值为 void*，接收时必须强制类型转换
    (*temp).data = x;
    temp->next=head;//当链表为空的时候 head 自然是NULL 该语句仍然成立 所以可以部分情况 写一个语句即可
    head = temp;
}
//打印链表
void Print()
{
    struct Node* temp = head;
    printf("link is: ");
    while(temp != NULL)//遍历链表
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    head = NULL;//链表是空的
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the numbers:\n");
        scanf("%d",&x);
        Insert(x);//从头结点处插入一个数
        Print();
    }
    return 0;
}
