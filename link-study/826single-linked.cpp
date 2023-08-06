#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int head, subscript, data[N], Next[N], m;

// 初始化链表
void initialize()
{
    head = -1;     // 初始为空链表
    subscript = 0; // 头节点指向的是下标地址从0开始的第一个节点位
}

// 从头部插入节点
void headInsert(int x)
{
    // 先把数据存进去
    data[subscript] = x;
    // 存储地址
    Next[subscript] = head;
    // 更新头节点的位置为刚插入的地址(因为是从头部插入节点)
    head = subscript++; // 自增1 便于下次插入时记录地址位
}

// 删除第k个数据后面的数据 所以要删除的应该是第k-1个数据
void Delete(int k)
{
    // Next[k] 表示的是k的下一个数据的地址
    Next[k] = Next[Next[k]];
}

// 在第x数后插入数据
void Insert(int k, int x)
{
    // 存储数据
    data[subscript] = x;
    // 存储地址    更新的地址应该指向原链表中 k所指向的地址(原来的k的后一个数据的地址)
    Next[subscript] = Next[k];
    // 更新原来的k的后一个数据的地址为 新插入的数据地址
    Next[k] = subscript++;
}
int main()
{
    initialize();
    cin >> m;
    while (m--)
    {
        int x, k;
        char c;
        cin >> c;
        if (c == 'H')
        {
            cin >> x;
            headInsert(x);
        }
        else if (c == 'D')
        {
            cin >> k;
            // 由于传入函数的数据是k-1，所以要对k=0的情况单独处理
            if (!k)
                head = Next[head]; // 如果删除头节点，那么就将头节点的下一个节点赋给头节点
            Delete(k - 1);
        }
        else
        {
            cin >> k >> x;
            Insert(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = Next[i])
        cout << data[i] << " ";
    cout << endl;
    return 0;
}
