#include<stdio.h>
# define m 4
int Sum(int x1,int y1,int x2,int y2,int arr[][m])
{
    int sum=0;
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1;j<=y2;j++)
        {
            sum+=arr[i][j];
        }
    }
    return sum;
}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<q;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",Sum(x1-1,y1-1,x2-1,y2-1,arr));
    }
    return 0;
}