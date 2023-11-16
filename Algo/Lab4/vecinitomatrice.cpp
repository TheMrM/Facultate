#include <iostream>
#include <vector>
using namespace std;

void ListaVeciniToMatriceAdiacenta(int* n, vector<vector<pair<int, int>>>* ListaVecini, vector<vector<int>>* MatAdiacenta) {
    MatAdiacenta->resize(*n, vector<int>(*n, 0));

    for (int i = 0; i < ListaVecini->size(); ++i) {
        for (const auto& vecin : (*ListaVecini)[i]) {
            int nodVecin = vecin.first;
            int cost = vecin.second;
            (*MatAdiacenta)[i][nodVecin] = cost;
        }
    }
}

void AfisareListaVecini(const vector<vector<pair<int, int>>>& ListaVecini) {
    cout << "Lista de vecini:\n";
    for (int i = 0; i < ListaVecini.size(); ++i) {
        cout << "Nodul " << i << " are vecinii: ";
        for (const auto& vecin : ListaVecini[i]) {
            cout << "(" << vecin.first << ", cost: " << vecin.second << ") ";
        }
        cout << endl;
    }
}

void AfisareMatriceAdiacenta(const vector<vector<int>>& MatAdiacenta) {
    cout << "\nMatricea de adiacenta:\n";
    for (const auto& rand : MatAdiacenta) {
        for (int val : rand) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3;
    vector<vector<pair<int, int>>> ListaVecini(n);
    vector<vector<int>> MatAdiacenta;

    ListaVecini[0] = {{1, 2}, {2, 4}};
    ListaVecini[1] = {{0, 2}};
    ListaVecini[2] = {{0, 4}};

    AfisareListaVecini(ListaVecini);

    ListaVeciniToMatriceAdiacenta(&n, &ListaVecini, &MatAdiacenta);
    AfisareMatriceAdiacenta(MatAdiacenta);

    return 0;
}