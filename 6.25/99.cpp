#include<iostream>
using namespace std;
const int N=5001;
int n,r;
int a[N][N];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>r;
    while(n--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        a[++x][++y] += w;
    }
    for(int i=1;i<5001;i++)
    {
        for(int j=1;j<5001;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<5001;i++)
    {
        for(int j=1;j<5001;j++)
        {
            ans=max(ans,a[i][j]-a[i-r][j]-a[i][j-r]+a[i-r][j-r]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int N = 5010;
int n,m;//m,n分别表示多少行多少列 
int s[N][N];//前缀和数组 
 
int main(){
    int cnt,r;//cnt价值点个数，r炸的范围 
    cin>>cnt>>r;
    r=min(r,5001);//炸的范围太大也没有意义，反正会全部炸掉 
    m=n=r;//保证m,n的下限 
    while(cnt--){
        int x,y,w;//表示x,y坐标和价值 
        cin>>x>>y>>w;
        x++,y++;//将坐标全部右移下移，保证所有坐标从1开始 
        m=max(m,y),n=max(n,x);
        s[x][y]+=w;//存权值 
    }
    //预处理前缀和
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    } 
    int res=0;
    //枚举所有边长r的矩形,枚举i,j 为右下角
    for(int i=r;i<=n;i++){
        for(int j=r;j<=m;j++){
            res=max(res,s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r]);
        }
    } 
     
    cout<<res<<endl;
    return 0;
}*/