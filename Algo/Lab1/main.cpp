//Assigurați-vă că aveți fișierele integer_input.txt și float_input.txt în directorul în care se află acest program

#include <iostream>
#include <fstream>
#include <algorithm>

void ReadArrayIntegerFromFile(int *x, int *n, std::string file) {
    std::ifstream inputFile(file);
    if (inputFile.is_open()) {
        inputFile >> *n;
        for (int i = 0; i < *n; i++) {
            inputFile >> x[i];
        }
        inputFile.close();
    } else {
        std::cerr << "Eroare la deschiderea fișierului " << file << std::endl;
    }
}

void WriteArrayIntegerToFile(int *x, int *n, std::string file) {
    std::ofstream outputFile(file);
    if (outputFile.is_open()) {
        outputFile << *n << "\n";
        for (int i = 0; i < *n; i++) {
            outputFile << x[i] << "\n";
        }
        outputFile.close();
    } else {
        std::cerr << "Eroare la deschiderea fișierului " << file << std::endl;
    }
}

void ReadArrayFloatFromFile(float *x, int *n, std::string file) {
    std::ifstream inputFile(file);
    if (inputFile.is_open()) {
        inputFile >> *n;
        for (int i = 0; i < *n; i++) {
            inputFile >> x[i];
        }
        inputFile.close();
    } else {
        std::cerr << "Eroare la deschiderea fișierului " << file << std::endl;
    }
}

void WriteArrayFloatToFile(float *x, int *n, std::string file) {
    std::ofstream outputFile(file);
    if (outputFile.is_open()) {
        outputFile << *n << "\n";
        for (int i = 0; i < *n; i++) {
            outputFile << x[i] << "\n";
        }
        outputFile.close();
    } else {
        std::cerr << "Eroare la deschiderea fișierului " << file << std::endl;
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
    std::sort(x, x + *n);
}

int MinMax(int *x, int *n, int MinMax) {
    if (*n == 0) {
        return 0; // Dacă șirul este gol, nu există minim sau maxim.
    }

    if (MinMax == 0) {
        return *std::min_element(x, x + *n); // Calculează minimul
    } else if (MinMax == 1) {
        return *std::max_element(x, x + *n); // Calculează maximul
    } else {
        return 0; // Valoare MinMax nevalidă
    }
}

float MinMax(float *x, int *n, int MinMax) {
    if (*n == 0) {
        return 0.0; // Dacă șirul este gol, nu există minim sau maxim.
    }

    if (MinMax == 0) {
        return *std::min_element(x, x + *n); // Calculează minimul
    } else if (MinMax == 1) {
        return *std::max_element(x, x + *n); // Calculează maximul
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

    std::cout << "Minimul din șirul de intregi: " << minInt << std::endl;
    std::cout << "Maximul din șirul de intregi: " << maxInt << std::endl;

    std::cout << "Minimul din șirul de numere reale: " << minFloat << std::endl;
    std::cout << "Maximul din șirul de numere reale: " << maxFloat << std::endl;

    return 0;
}
