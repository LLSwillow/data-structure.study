#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 10
int a[SIZE];
int front = -1, rear = -1;
void Enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if ((rear + 1 + SIZE) % SIZE == front)
    {
        return;
    }
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
    else if (front == rear)
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