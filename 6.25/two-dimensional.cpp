#include<iostream>
using namespace std;
const int N=1010;
int p[N][N],q[N][N];
int n,m,k;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d ",&p[i][j]);
            q[i][j]=q[i-1][j]+q[i][j-1]-q[i-1][j-1]+p[i][j];
        }
    }
    while(k--)
    {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",q[x2][y2]-q[x1-1][y2]-q[x2][y1-1]+q[x1-1][y1-1]);
    }
    return 0;
}
