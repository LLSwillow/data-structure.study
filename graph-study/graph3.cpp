#include <iostream>
#include <vector>
using namespace std;

// 邻接表节点的定义
struct AdjListNode {
    int dest;  // 目标顶点
    int weight;  // 边的权重
    AdjListNode* next;  // 下一个邻接表节点
};

// 邻接表中每个顶点的结构体
struct Vertex {
    AdjListNode* head;  // 邻接表头指针
};

class Graph {
private:
    int numVertices;
    vector<Vertex> adjacencyList;  // 邻接表

public:
    Graph(int vertices) : numVertices(vertices), adjacencyList(vertices, {nullptr}) {}

    void addEdge(int start, int end, int weight) {
        // 添加边到邻接表
        AdjListNode* newNode = new AdjListNode{end, weight, nullptr};
        newNode->next = adjacencyList[start].head;
        adjacencyList[start].head = newNode;

        // 无向图需要反向边
        newNode = new AdjListNode{start, weight, nullptr};
        newNode->next = adjacencyList[end].head;
        adjacencyList[end].head = newNode;
    }

    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            AdjListNode* current = adjacencyList[i].head;
            cout << "Adjacency List for vertex " << i << ": ";
            while (current != nullptr) {
                cout << "(" << current->dest << "," << current->weight << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 5);

    g.printGraph();

    return 0;
}
