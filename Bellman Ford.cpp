#include <iostream>
#include <climits>
using namespace std;

const int V = 5;
const int E = 8; 

void addEdge(int edges[E][3], int index, int u, int v, int w) {
    edges[index][0] = u;
    edges[index][1] = v;
    edges[index][2] = w;
}

void bellmanFord(int edges[E][3], int src) {
    int dist[V];


    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX; 
    dist[src] = 0;


    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative cycle!\n";
            return;
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": ";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int edges[E][3]; 

    addEdge(edges, 0, 0, 1, -1);
    addEdge(edges, 1, 0, 2, 4);
    addEdge(edges, 2, 1, 2, 3);
    addEdge(edges, 3, 1, 3, 2);
    addEdge(edges, 4, 1, 4, 2);
    addEdge(edges, 5, 3, 2, 5);
    addEdge(edges, 6, 3, 1, 1);
    addEdge(edges, 7, 4, 3, -3);

    bellmanFord(edges, 0);
    return 0;
}