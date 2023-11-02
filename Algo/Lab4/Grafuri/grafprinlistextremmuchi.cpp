#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n = 4;
    int m = 4;

    vector<pair<int, int>> edges;

    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 0));

    for (int i = 0; i < m; i++) {
        cout << "Edge " << i << " connects vertices " << edges[i].first << " and " << edges[i].second << endl;
    }

    return 0;
}