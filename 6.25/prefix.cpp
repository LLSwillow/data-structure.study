//前缀和算法
#include<iostream>
using namespace std;
const int N=1e5+10;
int n,m;
int p[N],q[N];
//把变量定义到主函数外面 会自动初始化0
int main()
{
    //紧盯输入格式来写
    scanf("%d %d",&n,&m);//n表示数组元素个数，m表示询问次数(测试个数)
    for(int i=1;i<=n;i++)//这里使数组下标从1开始存储数据，避免了下面q[i-1]出错。而且由于将数组定义为全局变量，自动初始化为0，q[0]=0方便了很多
    {
        scanf("%d ",&p[i]);
        q[i]=q[i-1]+p[i];
    }
    while(m--)//m--作为循环判断条件 后置-- 先使用后--
    {
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",q[r]-q[l-1]);
    }
    return 0;
}