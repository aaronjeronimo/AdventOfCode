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
    //int numeros[] = {7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1,-1};
    struct matriz {
        int matx[5][5] = {0};
    };
    vector <matriz> v;
    list <int> num;

    int bucle=0;
    do {
        num.push_back(numeros[bucle]);
        bucle++;
    } while (numeros[bucle] != -1);

    int lectura;
    int it=0;

    do {
        matriz m;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> lectura;
                m.matx[i][j] = lectura;
            }
        }

        v.push_back(m);
        it++;
    } while (it != 100);

    auto final = num.begin();
    for (auto i = num.begin(); i != num.end() && v.size() != 1; i++) {
        int numero = *i;

        for (int j = 0; j < v.size() && v.size() != 1; j++){
            for (int k = 0; k < 5; k++){
                for (int h = 0; h < 5; h++){
                    if (v.at(j).matx[k][h] == numero)
                        v.at(j).matx[k][h] = -1;
                }
            }

            bool vacia = true, salir = false;
            for (int k = 0; k < 5 && !salir; k++){

                for (int h = 0; h < 5 && vacia; h++){
                    if (v.at(j).matx[k][h] != -1)
                        vacia = false;
                }

                if (vacia)
                    salir = true;
                else
                    vacia = true;
            }

            for (int k = 0; k < 5 && !salir; k++){

                for (int h = 0; h < 5 && vacia; h++){
                    if (v.at(j).matx[h][k] != -1)
                        vacia = false;
                }

                if (vacia)
                    salir = true;
                else
                    vacia = true;
            }

            if (salir) {
                v.erase(v.begin()+j);
                j--;
            }
        }

        final = i;
    }

    bool terminar = false;
    for (auto j = final; !terminar; ++j){
        int numero = *j;

        for (int k = 0; k < 5; k++){
            for (int h = 0; h < 5; h++){
                if (v.at(0).matx[k][h] == numero)
                    v.at(0).matx[k][h] = -1;
            }
        }

        bool vacia = true, salir = false;
        for (int k = 0; k < 5 && !salir; k++){

            for (int h = 0; h < 5 && vacia; h++){
                if (v.at(0).matx[k][h] != -1)
                    vacia = false;
            }

            if (vacia)
                salir = true;
            else
                vacia = true;
        }

        for (int k = 0; k < 5 && !salir; k++){

            for (int h = 0; h < 5 && vacia; h++){
                if (v.at(0).matx[h][k] != -1)
                    vacia = false;
            }

            if (vacia)
                salir = true;
            else
                vacia = true;
        }

        if (salir) {
            final = j;
            terminar = true;
        }
    }

    int suma = 0;
    for (int k = 0; k < 5; k++) {
        for (int h = 0; h < 5; h++) {
            if (v.at(0).matx[k][h] != -1)
                suma += v.at(0).matx[k][h];
        }
    }

    cout << endl<< (suma*(*final)) << endl;
    return 0;
}