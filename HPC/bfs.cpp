#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<bool>& visited, int startNode) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        cout << currentNode << " ";

        #pragma omp parallel for
        for (int i = 0; i < graph[currentNode].size(); i++) {
            int neighborNode = graph[currentNode][i];

            if (!visited[neighborNode]) {
                visited[neighborNode] = true;
                #pragma omp critical
                q.push(neighborNode);
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    vector<vector<int>> graph(numNodes + 1); 
    vector<bool> visited(numNodes + 1, false); 

    cout << "Enter the edges:" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startNode;
    cout << "Enter the start node: ";
    cin >> startNode;

    double startTime = omp_get_wtime();

    cout << "BFS Traversal: ";
    bfs(graph, visited, startNode);
    cout << endl;

    double endTime = omp_get_wtime();
    double interval = (endTime - startTime)*1000.0;

    cout<<"Time taken: "<<interval<<" milliseconds"<<endl;

    return 0;
}