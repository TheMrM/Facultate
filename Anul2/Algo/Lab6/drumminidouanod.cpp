#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

#define INF INT_MAX

struct Edge {
    int destination;
    int weight;
};

struct Node {
    int id;
    int distance;
};

struct CompareNodes {
    bool operator()(const Node& a, const Node& b) {
        return a.distance > b.distance;
    }
};

void dijkstra(vector<vector<Edge>>& graph, int start, int end) {
    int numNodes = graph.size();
    vector<int> distances(numNodes, INF);
    vector<int> parents(numNodes, -1);

    priority_queue<Node, vector<Node>, CompareNodes> pq;
    pq.push({start, 0});
    distances[start] = 0;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.id;
        for (const Edge& neighbor : graph[u]) {
            int v = neighbor.destination;
            int weight = neighbor.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                parents[v] = u;
                pq.push({v, distances[v]});
            }
        }
    }

    cout << "Drumul minim intre nodurile " << start << " si " << end << " este: ";
    int current = end;
    vector<int> path;

    while (current != -1) {
        path.push_back(current);
        current = parents[current];
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0)
            cout << " -> ";
    }

    cout << "\nDistanta totala: " << distances[end] << endl;
}

int main() {
    vector<vector<Edge>> graph = {
        {{1, 2}, {2, 4}},
        {{2, 1}, {3, 7}, {4, 3}},
        {{3, 3}, {4, 1}},
        {{1, 2}, {2, 1}, {5, 4}},
        {{5, 2}},
        {{4, 2}}
    };

    int startNode = 0;
    int endNode = 3;

    dijkstra(graph, startNode, endNode);

    return 0;
}