#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    int numeros[] = {23,91,18,32,73,14,20,4,10,55,40,29,13,25,48,
                     65,2,80,22,16,93,85,66,21,9,36,47,72,88,58,5,
                     42,53,69,52,8,54,63,76,12,6,99,35,95,82,49,41,
                     17,62,34,51,77,94,7,28,71,92,74,46,79,26,19,97,
                     86,87,37,57,64,1,30,11,96,70,44,83,0,56,90,59,
                     78,61,98,89,43,3,84,67,38,68,27,81,39,15,50,60,
                     24,45,75,33,31,-1};
    vector <vector <vector <int>>> m;
    list <int> num;

    int bucle=0;
    do {
        num.push_back(numeros[bucle]);
        bucle++;
    } while (numeros[bucle] != -1);

    int lectura;
    int it=0;

    do {
        vector <vector <int>> matriz;
        for (int i = 0; i < 5; i++) {
            vector <int> fila;
            for (int j = 0; j < 5; j++) {
                cin >> lectura;
                fila.push_back(lectura);
            }
            matriz.push_back(fila);
        }

        m.push_back(matriz);
        it++;
    } while (it != 100);

    bool vacia = false;
    int ganadora = -1;
    auto final = num.begin();
    for (auto i = num.begin(); i != num.end() && !vacia; i++) {
        int numero = *i;

        for (int j = 0; j < m.size(); j++) {
            for (int k = 0; k < 5; k++) {
                for (int h = 0; h < m.at(j).at(k).size(); h++) {
                    if (m.at(j).at(k).at(h) == numero) {
                        m.at(j).at(k).erase(m.at(j).at(k).begin()+h);
                        h--;

                        if (m.at(j).at(k).empty()) {
                            ganadora = j;
                            vacia = true;
                        }
                    }
                }
            }
        }

        if (ganadora != -1)
            final = i;
    }

    int suma = 0;
    for (int k = 0; k < 5; k++) {
        for (int h = 0; h < m.at(ganadora).at(k).size(); h++) {
            suma += m.at(ganadora).at(k).at(h);
        }
    }

    cout << endl << (suma*(*final)) << endl;
    return 0;
}
