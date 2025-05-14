#include<iostream>
#include<queue>
#include<climits>
using namespace std;

const int v=7;

void addEdge(int graph[v][v],int u,int w,int wt)
{
    graph[u][w]=wt;
}

int findmin(int distance[v], bool visited[v])
{
    int min=INT_MAX;
    int pos=-1;
    for(int i=0;i<v;i++)
    {
        if (!visited[i] && distance[i] < min)
        {
        min = distance[i];
        pos = i;
        }
    }
    return pos;
}

void printPath(int parent[v], int end) 
{
    if (parent[end] == -1) {
        cout << end;
        return;
    }
    printPath(parent, parent[end]);
    cout << " -> " << end;
}

int dijkstras(int graph[v][v],int start,int end)
{
    int parent[v];
    int distance[v];
    bool visited[v]={false};
    int totalcost=0;

    for(int i=0;i<v;i++)
    {
        parent[i]=-1;
        distance[i]=INT_MAX;
    }

    visited[start]=true;
    distance[start]=0;

    queue<int>q;
    q.push(start);

    while(!q.empty())
    {
    int node=q.front();
    q.pop();
    
    for(int i=0;i<v;i++){
        if(graph[node][i]!=0 && visited[i]==false)
        {
        if(distance[node] + graph[node][i] < distance[i])
        {
            distance[i]=distance[node] + graph[node][i];
            parent[i]=node;
            q.push(i);
        }
        }
    }
    }

    if (distance[end] == INT_MAX) {
        cout << "No path exists from " << start << " to " << end << endl;
    } else {
        cout << "Shortest distance from " << start << " to " << end << ": " << distance[end] << endl;
        cout << "Path: ";
        printPath(parent, end);
        cout << endl;
    }
}

int main() {
    int graph[v][v] = {0};
    addEdge(graph, 0, 1, 28);
    addEdge(graph, 0, 5, 10);
    addEdge(graph, 1, 2, 16);
    addEdge(graph, 1, 6, 7);
    addEdge(graph, 2, 3, 12);
    addEdge(graph, 3, 6, 18);
    addEdge(graph, 3, 4, 22);
    addEdge(graph, 4, 6, 24);
    addEdge(graph, 4, 5, 25);

    dijkstras(graph, 0,3); // Find shortest path from 0 to 3
    return 0;
}