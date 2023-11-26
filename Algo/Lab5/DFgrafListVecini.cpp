#include <iostream>
#include <vector>

using namespace std;

void afiseazaGraf(const vector<vector<int>>& listaVecini) {
    cout << "Graficul initial (lista de vecini):" << endl;
    for (int i = 0; i < listaVecini.size(); i++) {
        cout << "Nod " << i << ": ";
        for (int vecin : listaVecini[i]) {
            cout << vecin << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void DFSUtil(int nod, int nivel, vector<bool>& vizitat, const vector<vector<int>>& listaVecini, int& contorVizita) {
    vizitat[nod] = true;
    cout << "Nod: " << nod << ", Nivel: " << nivel << ", Ordine Vizita: " << contorVizita++ << endl;

    // Afișarea vecinilor
    cout << "Vecini: ";
    for (int vecin : listaVecini[nod]) {
        cout << vecin << " ";
    }
    cout << endl;

    // Afișarea vecinilor vizitați
    cout << "Vecini Vizitati: ";
    for (int vecin : listaVecini[nod]) {
        if (vizitat[vecin]) {
            cout << vecin << " ";
        }
    }
    cout << endl << endl;

    // Parcurgerea vecinilor nevizitați
    for (int vecin : listaVecini[nod]) {
        if (!vizitat[vecin]) {
            DFSUtil(vecin, nivel + 1, vizitat, listaVecini, contorVizita);
        }
    }
}

void DFS(const vector<vector<int>>& listaVecini) {
    vector<bool> vizitat(listaVecini.size(), false);
    int contorVizita = 1;

    for (int i = 0; i < listaVecini.size(); i++) {
        if (!vizitat[i]) {
            DFSUtil(i, 0, vizitat, listaVecini, contorVizita);
        }
    }
}

int main() {
    vector<vector<int>> listaVecini = {
        {1, 2},
        {0, 3, 4},
        {0, 4},
        {1},
        {1, 2}
    };

    afiseazaGraf(listaVecini);

    cout << "Parcurgerea DFS a grafului cu detalii:" << endl;
    DFS(listaVecini);

    return 0;
}