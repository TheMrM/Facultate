#include <iostream>
#include <vector>
#include <set>
using namespace std;

void AfisareListaVecini(const vector<vector<int>>& ListaVecini) {
    cout << "Lista de vecini:" << endl;
    for (int i = 0; i < ListaVecini.size(); ++i) {
        cout << "Nodul " << i << " are vecinii: ";
        for (int vecin : ListaVecini[i]) {
            cout << vecin << " ";
        }
        cout << endl;
    }
}

void ListaVeciniToListaMuchii(int* n, vector<vector<int>>* ListaVecini, vector<pair<int, int>>* ListaMuchii) {
    set<pair<int, int>> muchiiUnice;
    for (int i = 0; i < *n; ++i) {
        for (int vecin : (*ListaVecini)[i]) {
            if (muchiiUnice.find(make_pair(vecin, i)) == muchiiUnice.end()) {
                muchiiUnice.insert(make_pair(i, vecin));
            }
        }
    }

    *ListaMuchii = vector<pair<int, int>>(muchiiUnice.begin(), muchiiUnice.end());
}

int main() {
    int n = 3;
    vector<vector<int>> ListaVecini = {{1, 2}, {0, 2}, {0, 1}};
    vector<pair<int, int>> ListaMuchii;

    AfisareListaVecini(ListaVecini);
    ListaVeciniToListaMuchii(&n, &ListaVecini, &ListaMuchii);

    cout << "Lista de muchii:" << endl;
    for (const auto& muchie : ListaMuchii) {
        cout << muchie.first << " - " << muchie.second << endl;
    }

    return 0;
}