//Asigurați-vă că aveți fișierele int_matrix.txt și float_matrix.txt în directorul în care se află acest program

#include <iostream>
#include <fstream>

void ReadMatIntegerFromFile(int **x, int *n, int *m, const std::string &file) {
    std::ifstream inputFile(file);
    if (inputFile.is_open()) {
        inputFile >> *n >> *m;
        for (int i = 0; i < *n; i++) {
            for (int j = 0; j < *m; j++) {
                inputFile >> x[i][j];
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Eroare la deschiderea fișierului " << file << std::endl;
    }
}

void WriteMatIntegerFromFile(int **x, int n, int m, const std::string &file) {
    std::ofstream outputFile(file);
    if (outputFile.is_open()) {
        outputFile << n << " " << m << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                outputFile << x[i][j] << " ";
            }
            outputFile << "\n";
        }
        outputFile.close();
    } else {
        std::cerr << "Eroare la deschiderea fișierului " << file << std::endl;
    }
}

void ReadMatFloatFromFile(float **x, int *n, int *m, const std::string &file) {
    std::ifstream inputFile(file);
    if (inputFile.is_open()) {
        inputFile >> *n >> *m;
        for (int i = 0; i < *n; i++) {
            for (int j = 0; j < *m; j++) {
                inputFile >> x[i][j];
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Eroare la deschiderea fișierului " << file << std::endl;
    }
}

void WriteMatFloatFromFile(float **x, int n, int m, const std::string &file) {
    std::ofstream outputFile(file);
    if (outputFile.is_open()) {
        outputFile << n << " " << m << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                outputFile << x[i][j] << " ";
            }
            outputFile << "\n";
        }
        outputFile.close();
    } else {
        std::cerr << "Eroare la deschiderea fișierului " << file << std::endl;
    }
}

int main() {
    const int maxSize = 100;
    int **intMatrix = new int*[maxSize];
    for (int i = 0; i < maxSize; i++) {
        intMatrix[i] = new int[maxSize];
    }
    float **floatMatrix = new float*[maxSize];
    for (int i = 0; i < maxSize; i++) {
        floatMatrix[i] = new float[maxSize];
    }

    int n, m;
    
    // Exemplu de citire și scriere a unei matrici de întregi
    ReadMatIntegerFromFile(intMatrix, &n, &m, "int_matrix.txt");
    WriteMatIntegerFromFile(intMatrix, n, m, "output_int_matrix.txt");

    // Exemplu de citire și scriere a unei matrici de numere reale
    ReadMatFloatFromFile(floatMatrix, &n, &m, "float_matrix.txt");
    WriteMatFloatFromFile(floatMatrix, n, m, "output_float_matrix.txt");

    for (int i = 0; i < maxSize; i++) {
        delete[] intMatrix[i];
        delete[] floatMatrix[i];
    }
    delete[] intMatrix;
    delete[] floatMatrix;

    return 0;
}
