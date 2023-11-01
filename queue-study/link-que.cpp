#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(int x)
{
    struct Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    // 如果队列为空
    if (front == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    struct Node *temp = front;
    // 队列为空
    if (front == NULL)
    {
        cout << "error" << endl;
        return;
    }
    // 队列不为空且仅有一个数据
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    // 释放删除数据所占存储空间
    free(temp);
}

// 返回队首元素
int Front()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }
    return front->data;
}
// 打印队列元素
void Print()
{
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Enqueue(2);
    Print();
    Enqueue(4);
    Print();
    Enqueue(6);
    Print();
    Dequeue();
    Print();
    Enqueue(8);
    Print();
    return 0;
}