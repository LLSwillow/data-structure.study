#include<stdio.h>

int Sum(int l,int r,int arr[])
{
    int sum=0;
    for(int i=l;i<=r;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int l,r;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n",Sum(l-1,r-1,arr));
    }
}