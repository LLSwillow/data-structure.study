#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N];
long long q1[N];
int n,q;
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        q1[i]=q1[i-1]+p[i];
    }
    while(q--)
    {
        int f,t;
        cin>>f>>t;
        printf("%lld\n",q1[t]-q1[f-1]);//这里注意longlong类型的数据 格式化输出 应为%lld 否则会出错
    }
    return 0;
}