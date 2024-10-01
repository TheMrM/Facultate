# Laborator - Lucrul cu Elemente `const` si `static`

In acest laborator, am creat o clasa numita `ProdusAlimentar` care reprezinta un produs alimentar si care utilizeaza elemente `const` si `static` pentru a gestiona cota TVA si alte atribute ale produsului.

## Clasa ProdusAlimentar

Clasa `ProdusAlimentar` are urmatoarele atribute si metode:

- `const int cod`: Un membru constant care reprezinta codul unic al produsului.
- `int pret`: Pretul produsului.
- `int cantitate`: Cantitatea produsului.
- `string denumire`: Denumirea produsului.
- `static int cotaTVA`: Un membru static care reprezinta cota TVA comuna pentru toate produsele.

Metodele clasei:

- Constructorul `ProdusAlimentar(int c, string d, int p, int q)`: Initializeaza obiectul `ProdusAlimentar` cu un cod, denumire, pret si cantitate.
- `int calculValoareProdus()`: Calculeaza valoarea produsului cu TVA.
- `void afisareProdus()`: Afiseaza informatiile despre produs, inclusiv cod, denumire, pret, cantitate, valoarea cu TVA si cota TVA.
- `static void modificareCotaTVA(int nouaCotaTVA)`: Modifica cota TVA pentru toate produsele.

## Exemplu de Utilizare

In `main()`, am creat mai multe obiecte `ProdusAlimentar` cu valori diferite si am afisat informatiile despre ele inainte si dupa modificarea cotei TVA.

## Cum sa Compilati si Sa Rulati

1. Compilati codul utilizand un compilator C++ (de exemplu, g++):
    ```
    g++ Alimente2.cpp -o nume_program
    ```
2. Rulati programul:
    ```
    ./nume_program
    ```

## Contributii

Acest proiect a fost creat in scop educational pentru laboratorul de C++. Orice contributii sau sugestii sunt binevenite.