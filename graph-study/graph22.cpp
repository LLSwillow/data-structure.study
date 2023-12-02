#include<iostream>
#include<vector>
using namespace std;
class Graph{
private:
    int vertexs;
    vector<vector<int>> edges;//创建二维数组
public:

    // 构造函数，初始化图的大小
    Graph(int vertices) : vertexs(vertices), edges(vertexs,vector<int>(vertexs, 0)) {}

    void Pushv(int i,int j)//无向图
    {
        edges[i][j]=1;
        edges[j][i]=1;
    }
    void Print()
    {
        for(int i=0;i<vertexs;i++)
        {
            for(int j=0;j<vertexs;j++)
            {
                cout<<edges[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g(5);
    g.Pushv(0,1);
    g.Pushv(0,2);
    g.Pushv(1,2);
    g.Pushv(2,3);
    g.Pushv(3,4);
    g.Pushv(4,1);
    g.Print();
    return 0;
}