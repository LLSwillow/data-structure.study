// 中缀表达式 转 后缀表达式
#include <iostream>
#include <stack>
using namespace std;
// 判断括号
bool Bracket(char a)
{
    if (a == '(' || a == '{' || a == '[' || a == ')' || a == '}' || a == ']')
        return 0;
    return 1;
}
// 判断操作符优先级
int GetOperatorWeight(char op)
{
    int weight = -1;
    switch (op)
    {
    case '+':
    case '-':
        weight = 1;
        break;
    case '*':
    case '/':
        weight = 2;
        break;
    }
    return weight;
}
int HasHigher(char op1, char op2)
{
    if (op1 == '(' || op1 == '[' || op1 == '{')
        return false;
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);
    return op1Weight > op2Weight ? true : false;
}
// 判断是否是操作符
bool Isoperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/')
        return 1;
    return 0;
}

string exchange(string A)
{
    stack<char> S;
    string postfix = "";
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == ' ')
            continue;
        else if (A[i] >= 48 && A[i] <= 57) // 操作数
        {
            while (A[i] != ' ' && i < A.size())
            {
                postfix.push_back(A[i++]);
            }
            postfix.push_back(' '); // 添加空格以区分操作数
        }
        else if (Isoperator(A[i])) // 操作符
        {
            while (!S.empty() && HasHigher(S.top(), A[i]) && Bracket(S.top()))
            {
                postfix.push_back(S.top());
                S.pop();
            }
            S.push(A[i]);
        }
        else if (A[i] == '(' || A[i] == '{' || A[i] == '[') // 括号
        {
            S.push(A[i]);
        }
        else if (A[i] == ')' || A[i] == '}' || A[i] == ']')
        { // 右括号：左括号之前的操作符均出栈之后，弹出左括号
            while (!S.empty() && S.top() != '(' && S.top() != '{' && S.top() != '[')
            {
                postfix.push_back(S.top());
                S.pop();
            }
            S.pop();
        }
    }
    // 遍历完字符串中元素之后，弹出栈中剩余元操作符
    while (!S.empty())
    {
        postfix += S.top();
        S.pop();
    }
    return postfix;
}
int main()
{
    string A;
    cout << "Enter Infix Expression \n";
    getline(cin, A);
    string postfix = exchange(A);
    cout << "Output = " << postfix << "\n";
    return 0;
}