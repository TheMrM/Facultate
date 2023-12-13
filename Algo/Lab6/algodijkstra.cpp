#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

#define V 9

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(const vector<int>& parent, int j);

void printSolution(int dist[], const vector<int>& parent, int src) {
    cout << "Distantele minime de la sursa la noduri:\n";
    for (int i = 0; i < V; i++) {
        cout << "Nodul " << i << ": Distanta " << dist[i] << ", Drumul: " << src << " ";
        printPath(parent, i);
        cout << endl;
    }
}

void printPath(const vector<int>& parent, int j) {

    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    cout << j << " ";
}

void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];
    bool sptSet[V];
    vector<int> parent(V, -1);

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }

    printSolution(dist, parent, src);
 
    if (src != dest) {
        printPath(parent, dest);
    }
}

int main() {
    
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0, 5);

    return 0;
}