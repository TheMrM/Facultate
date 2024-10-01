//Assigurați-vă că aveți fișierele integer_input.txt și float_input.txt în directorul în care se află acest program

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void ReadArrayIntegerFromFile(int *x, int *n, string file) {
    ifstream inputFile(file);
    if (inputFile.is_open()) {
        inputFile >> *n;
        for (int i = 0; i < *n; i++) {
            inputFile >> x[i];
        }
        inputFile.close();
    } else {
        cerr << "Eroare la deschiderea fișierului " << file << endl;
    }
}

void WriteArrayIntegerToFile(int *x, int *n, string file) {
    ofstream outputFile(file);
    if (outputFile.is_open()) {
        outputFile << *n << "\n";
        for (int i = 0; i < *n; i++) {
            outputFile << x[i] << "\n";
        }
        outputFile.close();
    } else {
        cerr << "Eroare la deschiderea fișierului " << file << endl;
    }
}

void ReadArrayFloatFromFile(float *x, int *n, string file) {
    ifstream inputFile(file);
    if (inputFile.is_open()) {
        inputFile >> *n;
        for (int i = 0; i < *n; i++) {
            inputFile >> x[i];
        }
        inputFile.close();
    } else {
        cerr << "Eroare la deschiderea fișierului " << file << endl;
    }
}

void WriteArrayFloatToFile(float *x, int *n, string file) {
    ofstream outputFile(file);
    if (outputFile.is_open()) {
        outputFile << *n << "\n";
        for (int i = 0; i < *n; i++) {
            outputFile << x[i] << "\n";
        }
        outputFile.close();
    } else {
        cerr << "Eroare la deschiderea fișierului " << file << endl;
    }
}

int BinarySearch(int *x, int *n, int elem) {
    int left = 0;
    int right = *n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (x[mid] == elem) {
            return mid;
        }
        if (x[mid] < elem) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Elementul nu a fost găsit
}

void QuickSort(int *x, int *n) {
    sort(x, x + *n);
}

int MinMax(int *x, int *n, int MinMax) {
    if (*n == 0) {
        return 0; // Dacă șirul este gol, nu există minim sau maxim.
    }

    if (MinMax == 0) {
        return *min_element(x, x + *n); // Calculează minimul
    } else if (MinMax == 1) {
        return *max_element(x, x + *n); // Calculează maximul
    } else {
        return 0; // Valoare MinMax nevalidă
    }
}

float MinMax(float *x, int *n, int MinMax) {
    if (*n == 0) {
        return 0.0; // Dacă șirul este gol, nu există minim sau maxim.
    }

    if (MinMax == 0) {
        return *min_element(x, x + *n); // Calculează minimul
    } else if (MinMax == 1) {
        return *max_element(x, x + *n); // Calculează maximul
    } else {
        return 0.0; // Valoare MinMax nevalidă
    }
}

int main() {
    const int maxSize = 100;
    int intArray[maxSize];
    float floatArray[maxSize];
    int intArraySize = 0;
    int floatArraySize = 0;

    ReadArrayIntegerFromFile(intArray, &intArraySize, "integer_input.txt");
    ReadArrayFloatFromFile(floatArray, &floatArraySize, "float_input.txt");

    WriteArrayIntegerToFile(intArray, &intArraySize, "integer_output.txt");
    WriteArrayFloatToFile(floatArray, &floatArraySize, "float_output.txt");

    QuickSort(intArray, &intArraySize);

    int minInt = MinMax(intArray, &intArraySize, 0);
    int maxInt = MinMax(intArray, &intArraySize, 1);

    float minFloat = MinMax(floatArray, &floatArraySize, 0);
    float maxFloat = MinMax(floatArray, &floatArraySize, 1);

    cout << "Minimul din șirul de intregi: " << minInt << endl;
    cout << "Maximul din șirul de intregi: " << maxInt << endl;

    cout << "Minimul din șirul de numere reale: " << minFloat << endl;
    cout << "Maximul din șirul de numere reale: " << maxFloat << endl;

    return 0;
}
