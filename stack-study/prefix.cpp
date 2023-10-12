//前缀表达式
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int calculate(int x, int y, char z)
{
    if (z == '+')
        return x + y;
    else if (z == '-')
        return x - y;
    else if (z == '*')
        return x * y;
    else
    {
        if (y == 0)
        {
            cout << "error";
            return 0;
        }
        return x / y;
    }
}
int Prefix(char A[],int n)
{
    int op1, op2, res;
    stack<string> S;
    for (int i = n-1; i >= 0; i--)
    {
        char ch[] = {0};
        int j = 0;
        // 判断是否需要入栈
        if (A[i] == ' ')
            continue;
        else if (A[i] >= 48 && A[i] <= 57)
        {
            // while(A[++i]!=' ')
            while (i >= 0 && A[i] != ' ')
            {
                ch[j++] = A[i--];
            }
            S.push(ch);
        }
        else
        {
            op1 = stoi(S.top());
            S.pop();
            if (S.empty())
            {
                cout << "error";
                return 0;
            }
            op2 = stoi(S.top()); // 转化为int型数据
            S.pop();
            res = calculate(op1, op2, A[i]);
            S.push(to_string(res));//转化为字符串型
        }
    }
    return stoi(S.top());
}
int main()
{
    char A[101];
    printf("Enter a string: ");
    gets(A);
    int ans = Prefix(A, strlen(A));
    cout << ans;
    return 0;
}