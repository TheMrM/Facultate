#include <iostream>
#include <vector>

using namespace std;

void DFS(int nod, vector<bool>& vizitat, const vector<vector<int>>& listaAdiacenta, vector<int>& componenta) {
    vizitat[nod] = true;
    componenta.push_back(nod);

    for (int vecin : listaAdiacenta[nod]) {
        if (!vizitat[vecin]) {
            DFS(vecin, vizitat, listaAdiacenta, componenta);
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> listaAdiacenta(n + 1);
    vector<bool> vizitat(n + 1, false);
    vector<vector<int>> componenteConexe;

    vector<pair<int, int>> perechi = {{3, 4}, {8, 9}, {7, 9}, {5, 7}};
    for (auto& pereche : perechi) {
        listaAdiacenta[pereche.first].push_back(pereche.second);
        listaAdiacenta[pereche.second].push_back(pereche.first);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vizitat[i]) {
            vector<int> componenta;
            DFS(i, vizitat, listaAdiacenta, componenta);
            componenteConexe.push_back(componenta);
        }
    }

    cout << "Grupurile de prieteni sunt:" << endl;
    for (const auto& grup : componenteConexe) {
        for (int prieten : grup) {
            cout << prieten << " ";
        }
        cout << endl;
    }

    return 0;
}