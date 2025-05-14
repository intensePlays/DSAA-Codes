#include <iostream>
using namespace std;

const int v = 4; // Vertices
const int max_edges = v * (v - 1) / 2; // Max edges in undirected graph

void addEdge(int graph[v][v], int u, int w, int wt) {
    graph[u][w] = wt;
    graph[w][u] = wt;
}

void sortEdges(int edgeList[max_edges][3], int edgeCount) {
    // Bubble Sort (simple, no vectors)
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edgeList[j][2] > edgeList[j + 1][2]) {
                // Swap src, dest, weight
                swap(edgeList[j][0], edgeList[j + 1][0]);
                swap(edgeList[j][1], edgeList[j + 1][1]);
                swap(edgeList[j][2], edgeList[j + 1][2]);
            }
        }
    }
}

int findParent(int parent[], int i) {
    if (parent[i] == -1) return i;
    return findParent(parent, parent[i]);
}

void kruskals(int graph[v][v]) {
    int edgeList[max_edges][3]; // [src, dest, weight]
    int edgeCount = 0;

    // Extract edges (upper triangle to avoid duplicates)
    for (int i = 0; i < v; i++) {
        for (int j = i + 1; j < v; j++) {
            if (graph[i][j] != 0) {
                edgeList[edgeCount][0] = i;
                edgeList[edgeCount][1] = j;
                edgeList[edgeCount][2] = graph[i][j];
                edgeCount++;
            }
        }
    }

    sortEdges(edgeList, edgeCount);

    int parent[v];
    for (int i = 0; i < v; i++) parent[i] = -1;

    cout << "Edges in MST:\n";
    int totalWeight = 0;
    int mstEdges = 0;

    for (int i = 0; i < edgeCount && mstEdges < v - 1; i++) {
        int src = edgeList[i][0];
        int dest = edgeList[i][1];
        int weight = edgeList[i][2];

        int srcParent = findParent(parent, src);
        int destParent = findParent(parent, dest);

        if (srcParent != destParent) {
            cout << src << "-" << dest << " : " << weight << "\n";
            totalWeight += weight;
            parent[destParent] = srcParent; // Union
            mstEdges++;
        }
    }

    cout << "Total MST Weight: " << totalWeight << "\n";
}

int main() {
    int graph[v][v] = {0};
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 6);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 1, 3, 15);
    addEdge(graph, 2, 3, 4);

    kruskals(graph);
    return 0;
}