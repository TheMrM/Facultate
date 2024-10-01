#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Edge {
  int source;
  int destination;
  int weight;

  Edge(int source, int destination, int weight) : source(source), destination(destination), weight(weight) {}

  bool operator<(const Edge& other) const {
    return weight < other.weight;
  }
};

class Prim {
public:
  Prim(vector<Edge>& edges, int startVertex) : edges(edges), startVertex(startVertex) {}

  vector<Edge> findMST() {
    vector<Edge> mst;

    vector<bool> visited(edges.size(), false);
    visited[startVertex] = true;

    set<Edge> candidateEdges;
    for (Edge edge : edges) {
      if (edge.source == startVertex) {
        candidateEdges.insert(edge);
      }
    }

    while (!candidateEdges.empty()) {
      Edge edge = *candidateEdges.begin();
      candidateEdges.erase(edge);

      mst.push_back(edge);

      int destination = edge.destination;
      visited[destination] = true;

      for (Edge candidateEdge : edges) {
        if (candidateEdge.destination == destination && !visited[candidateEdge.source]) {
          candidateEdges.insert(candidateEdge);
        }
      }
    }

    return mst;
  }

private:
  vector<Edge> edges;
  int startVertex;
};

int main() {
  vector<Edge> edges = {
    {0, 1, 10}, {0, 2, 6}, {1, 3, 15}, {2, 3, 9}, {3, 4, 8},
  };

  Prim prim(edges, 0);
  vector<Edge> mst = prim.findMST();

  for (Edge edge : mst) {
    cout << edge.source << " - " << edge.destination << " (cost: " << edge.weight << ")" << endl;
  }

  return 0;
}