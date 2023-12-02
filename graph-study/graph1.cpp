#include<iostream>
#include<vector>
using namespace std;
struct edge{
    int v1;
    int v2;
    int weight;
};
class Graph{
public:
    //创建两个动态数组
    vector<int> v;
    vector<struct edge> e;

    void Pushv(int x)
    {
        v.push_back(x);
    }

    void Pushe(int x1,int x2,int w)
    {
        e.push_back({x1,x2,w});
    }

    void Printg()
    {
        for(auto &edge:e)
        {
            cout<<"edges:"<<edge.v1<<"-"<<edge.v2<<"-"<<edge.weight;
        }
        for(auto &v:v)
        {
            cout<<"vertexs:"<<v<<" ";
        }
    }
    //无向图找给定节点的相邻节点
    vector<int> Findnei(int node)
    {
        vector<int> neighbors;
        for(auto &edge:e)
        {
            if(edge.v1==node)
            {
                neighbors.push_back(edge.v2);
            }
            else if(edge.v2==node)
            {
                neighbors.push_back(edge.v1);
            }
        }
        return neighbors;
    }
    //判断两个给定节点是否相连
    bool link(int n1,int n2)
    {
        for(auto &edge:e)
        {
            if((edge.v1==n1 && edge.v2==n2) || (edge.v1==n2 && edge.v2==n1))
            {
                return 1;
            }
        }
        return 0;
    }
};
//无向图找给定节点的相邻节点
vector<int> Findneig(Graph &g,int node)
{
    vector<int> neighbors;
    for(auto &edge:g.e)
    {
        if(edge.v1==node)
        {
            neighbors.push_back(edge.v2);
        }
    }
    return neighbors;
}
int main()
{
    //创建图
    Graph g;
    g.Pushv(1);
    g.Pushv(10);
    g.Pushv(12);
    g.Pushv(15);
    g.Pushe(1,10,5);
    g.Pushe(1,12,6);
    g.Pushe(1,15,8);
    g.Pushe(10,15,10);
    return 0;
}