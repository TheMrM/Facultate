#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void ListaMuchiiToMatriceAdiacenta(int n, vector<pair<int, int>>& ListaMuchii, vector<vector<int>>& MatAdiacenta) {
    for (const auto& muchie : ListaMuchii) {
        int u = muchie.first;
        int v = muchie.second;
        MatAdiacenta[u][v] = 1;
    }
}

void AfisareMatrice(const vector<vector<int>>& MatAdiacenta) {
    for (const auto& rand : MatAdiacenta) {
        for (int val : rand) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    int m = 7;

    srand(time(nullptr));
    
    vector<vector<int>> MatAdiacenta(n, vector<int>(n, 0));
    cout << "Matricea initiala:\n";
    AfisareMatrice(MatAdiacenta);

    vector<pair<int, int>> ListaMuchii;
    for (int i = 0; i < m; ++i) {
        int u = rand() % n;
        int v = rand() % n;
        ListaMuchii.push_back(make_pair(u, v));
    }

    ListaMuchiiToMatriceAdiacenta(n, ListaMuchii, MatAdiacenta);

    cout << "\nMuchii:\n";
    for (const auto& muchie : ListaMuchii) {
        cout << muchie.first << " - " << muchie.second << endl;
    }

    cout << "\nMatricea de adiacenta dupa adaugarea muchiilor:\n";
    AfisareMatrice(MatAdiacenta);

    return 0;
}