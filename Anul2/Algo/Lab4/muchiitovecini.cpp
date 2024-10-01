#include <iostream>
#include <vector>
using namespace std;

void ListaMuchiiToListaVecini(int* n, int* m, vector<pair<int, int>>* ListaMuchii, vector<vector<int>>* ListaVecini) {
    cout << "Introduceti numarul de noduri: ";
    cin >> *n;
    cout << "Introduceti numarul de muchii: ";
    cin >> *m;

    ListaMuchii->resize(*m);
    cout << "Introduceti muchiile (nod1 nod2):" << endl;
    for (int i = 0; i < *m; ++i) {
        cin >> (*ListaMuchii)[i].first >> (*ListaMuchii)[i].second;
    }

    ListaVecini->resize(*n);
    for (const auto& muchie : *ListaMuchii) {
        (*ListaVecini)[muchie.first].push_back(muchie.second);
        (*ListaVecini)[muchie.second].push_back(muchie.first);
    }
}

void AfisareListaVecini(const vector<vector<int>>& ListaVecini) {
    cout << "Reprezentarea grafica sub forma de lista de vecini:\n";
    for (int i = 0; i < ListaVecini.size(); ++i) {
        cout << "Nodul " << i << " este conectat cu nodurile: ";
        for (const auto& vecin : ListaVecini[i]) {
            cout << vecin << " ";
        }
        cout << endl;
    }
    cout << "Fiecare linie reprezinta un nod si nodurile cu care este conectat direct.\n";
}

int main() {
    int n, m;
    vector<pair<int, int>> ListaMuchii;
    vector<vector<int>> ListaVecini;

    ListaMuchiiToListaVecini(&n, &m, &ListaMuchii, &ListaVecini);
    AfisareListaVecini(ListaVecini);

    return 0;
}
