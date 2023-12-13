#include <iostream>
#include <fstream>
#include <limits.h>
#include <vector>

using namespace std;

#define INF INT_MAX
#define V 4

void printSolution(int dist[][V]);

void floydWarshall(int graph[][V]) {
    int dist[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V]) {
    cout << "Matricea drumurilor minime intre noduri:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ifstream fin("../graph.txt");
    int graph[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fin >> graph[i][j];
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    fin.close();

    floydWarshall(graph);

    return 0;
}