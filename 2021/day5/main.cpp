#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int TAM = 1000;
    int m[TAM][TAM];

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            m[i][j] = 0;

    int lectura[4];
    string l, numero;
    getline(cin, l);
    int j = 0;
    for (int i = 0; i < l.length(); i++) {
        if (isdigit(l.at(i)))
            numero.push_back(l.at(i));
        else if (numero != "") {
            lectura[j] = stoi(numero);
            j++;
            numero = "";
        }
    }
    lectura[j] = stoi(numero);

    do {
        if (lectura[0] == lectura[2])
            for (int i = min(lectura[1],lectura[3]); i <= max(lectura[1],lectura[3]); i++)
                m[lectura[0]][i]++;
        else if (lectura[1] == lectura[3])
            for (int i = min(lectura[0],lectura[2]); i <= max(lectura[0],lectura[2]); i++)
                m[i][lectura[1]]++;
        else {
            int sumax,sumay;

            if (lectura[0] <= lectura[2])
                sumax = 1;
            else
                sumax = -1;

            if (lectura[1] <= lectura[3])
                sumay = 1;
            else
                sumay = -1;

            int j = lectura[1], i = lectura[0];
            while (i != (lectura[2]+sumax) && j != (lectura[3]+sumay)) {
                m[i][j]++;
                i += sumax;
                j += sumay;
            }
        }

        l.clear();
        numero.clear();
        getline(cin, l);
        int j = 0;
        for (int i = 0; i < l.length(); i++) {
            if (isdigit(l.at(i)))
                numero.push_back(l.at(i));
            else if (numero != "") {
                lectura[j] = stoi(numero);
                j++;
                numero = "";
            }
        }
        if (numero != "")
            lectura[j] = stoi(numero);
    } while (l != "hola");

    int inter = 0;
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (m[i][j] >= 2)
                inter++;

    cout << endl << inter << endl;

    return 0;
}
