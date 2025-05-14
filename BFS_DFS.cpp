#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;
int graph[MAX][MAX];   
bool visited[MAX];    

void BFS(int start, int vertices) {
    bool visited[MAX] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from node " << start << ": ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void DFS(int node, int vertices) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter " << edges << " edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    int start;
    cout << "\nEnter starting node for traversal: ";
    cin >> start;

    BFS(start, vertices);

    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    cout << "DFS Traversal starting from node " << start << ": ";
    DFS(start, vertices);
    cout << endl;

    return 0;
}
