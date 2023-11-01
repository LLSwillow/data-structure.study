#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 10
int a[SIZE];
int front = -1, rear = -1;
void Enqueue(int x)
{
    //空队列
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    //队列已满
    else if ((rear + 1 + SIZE) % SIZE == front)//如果rear指针的 下一个位置 等于front指针的当前位置，那么表示队列已满，无法进行插入操作
    {
        return;
    }
    //正常插入
    else
    {
        rear = (rear + 1 + SIZE) % SIZE;
    }
    a[rear] = x;
}
void Dequeue()
{
    if (front == -1 && rear == -1)
        return;
    else if (front == rear)//而在删除时，如果front指针的 当前位置 等于rear指针的当前位置，那么表示队列为空
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1 + SIZE) % SIZE;
    }
}
int main()
{
    Enqueue(2);
    Enqueue(20);
    Enqueue(25);
    Enqueue(7);
    Enqueue(25);
    Dequeue();
    Dequeue();
    for (int i = front; i != rear; i = (i + 1) % SIZE)
    {
        cout << a[i] << " ";
    }
    cout << a[rear] << endl;
    return 0;
}