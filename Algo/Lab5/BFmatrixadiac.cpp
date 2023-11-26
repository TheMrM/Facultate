#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printmatriceAdiacenta(const vector<vector<int>>& matriceAdiacenta) {
    for (const auto& rand : matriceAdiacenta) {
        for (int element : rand) {
            cout << element << " ";
        }
        cout << endl;
    }
}

void BFS(int nodPornire, const vector<vector<int>>& matriceAdiacenta, vector<bool>& visitat) {
    queue<int> q;
    queue<int> niveluri; // Coada pentru niveluri
    visitat[nodPornire] = true;
    q.push(nodPornire);
    niveluri.push(0); // Nivelul de start este 0

    while (!q.empty()) {
        int nod = q.front();
        int nivel = niveluri.front();
        q.pop();
        niveluri.pop();

        // Calcularea numărului de noduri adiacente și listarea lor
        int numarNoduriAdiacente = 0;
        string noduriAdiacente = "";

        for (int i = 0; i < matriceAdiacenta[nod].size(); i++) {
            if (matriceAdiacenta[nod][i]) {
                numarNoduriAdiacente++;
                noduriAdiacente += to_string(i) + " ";
            }
        }

        // Afișarea nodului curent și a informațiilor suplimentare
        cout << "Nod: " << nod << ", Nivel: " << nivel << ", Noduri Adiacente: " << numarNoduriAdiacente << " [ " << noduriAdiacente << "]" << endl;

        // Parcurgerea nodurilor adiacente nevizitate
        for (int i = 0; i < matriceAdiacenta[nod].size(); i++) {
            if (matriceAdiacenta[nod][i] && !visitat[i]) {
                visitat[i] = true;
                q.push(i);
                niveluri.push(nivel + 1); // Următorul nivel
            }
        }
    }
}

int main() {
    vector<vector<int>> matriceAdiacenta = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0}
    };

    vector<bool> visitat(matriceAdiacenta.size(), false);

    cout << "Matricea de adiacenta:" << endl;
    printmatriceAdiacenta(matriceAdiacenta);
    cout << endl;

    cout << "Parcurgerea BFS:" << endl;
    BFS(0, matriceAdiacenta, visitat);

    return 0;
}