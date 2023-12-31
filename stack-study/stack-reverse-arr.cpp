//用栈反转字符串
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
// 数组呈现的栈
void Reverse(char C[], int n)
{
    stack<char> S;
    //入栈
    for (int i = 0; i < n; i++)
    {
        S.push(C[i]);
    }

    for (int i = 0; i < n; i++)
    {
        C[i] = S.top();//逆序了
        S.pop();
    }
}
int main()
{
    char C[51];
    printf("Enter a string: ");
    gets(C);
    Reverse(C, strlen(C));
    printf("Output = %s", C);
    return 0;
}