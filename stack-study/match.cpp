#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool isMatch(char A[],int n)
{
    char x1='}',y1=')',z1=']',x2='{',y2='(',z2='[';
    stack<char> S;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='{' || A[i]=='(' || A[i]=='[')S.push(A[i]);
        else{//如果栈中为空或者不匹配 就return 否则就出栈
            if(S.empty() || (A[i]==x1 && S.top()!=x2) || (A[i]==y1 && S.top()!=y2) || (A[i]==z1 && S.top()!=z2)) return 0;
            else S.pop();
        }
    }
    //整个数组中的元素遍历完之后，就要判断是否完全匹配了。而判断条件就是 栈是否为空
    return S.empty();
}
int main()
{
    char A[51];
    printf("Enter a string: ");
    gets(A);
    bool ans=isMatch(A,strlen(A));
    cout<<ans;
    return 0;
}