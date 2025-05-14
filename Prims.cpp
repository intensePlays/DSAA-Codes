#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX];    // Stores MST
    int key[MAX];       // Minimum edge weights
    bool mstSet[MAX];   // Tracks visited nodes

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;      // Start from node 0
    parent[0] = -1;  // No parent for start

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;

        for (int v = 0; v < V; v++)
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
            }

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    cout << "\nPrim's MST:\n";
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }
    cout << "Total Minimum Cost: " << totalCost << endl;
}

int main() {
    int V, E;
    int graph[MAX][MAX] = {0};

    cout << "Enter number of offices (vertices): ";
    cin >> V;

    cout << "Enter number of connections (edges): ";
    cin >> E;

    cout << "Enter edges (source destination cost):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    primMST(graph, V);

    return 0;
}
