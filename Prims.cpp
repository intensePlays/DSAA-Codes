#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int v=10;

void addEdge(int graph[v][v], int u, int w, int wt) {
	graph[u][w]=wt;
	graph[w][u]=wt;
}

int findmin(int distance[v], bool visited[v]) {
	int min=INT_MAX;
	int pos=-1;
	for(int i=0; i<v; i++) {
		if(!visited[i] && distance[i]<min) {
			min=distance[i];
			pos=i;
		}
	}
	return pos;
}

void Prims(int graph[v][v], int start) {
	bool visited[v]= {false};
	int parent[v];
	int distance[v];
	int total_cost=0;

	for(int i=0; i<v; i++) {
		distance[i]=INT_MAX;
		parent[i]=-1;
	}

	visited[start]=true;
	distance[start]=0;

	queue<int>q;
	q.push(start);

	while(!q.empty()) {
		int node=q.front();
		q.pop();

		cout<<node<<" ";

		for(int i=0; i<v; i++) {
			if(graph[node][i]!=0 && graph[node][i]<distance[i] && visited[i]==false) {
				distance[i]=graph[node][i];
				parent[i]=node;
			}
		}
		int next=findmin(distance, visited);
		if(next != -1) {
			cout<<parent[next]<<" - "<<next<<": "<<distance[next]<<endl;
			total_cost += distance[next];
			visited[next]=true;
			q.push(next);
		}
	}
	cout<<"Total cost of MST: "<<total_cost<<endl;
}

int main() {
	int graph[v][v]= {0};
	addEdge(graph, 0, 1, 28);
	addEdge(graph, 0, 5, 10);
	addEdge(graph, 1, 2, 16);
	addEdge(graph, 1, 6, 7);
	addEdge(graph, 2, 3, 12);
	addEdge(graph, 3, 6, 18);
	addEdge(graph, 3, 4, 22);
	addEdge(graph, 4, 6, 24);
	addEdge(graph, 4, 5, 25);

	Prims(graph, 0);
	return 0;

}