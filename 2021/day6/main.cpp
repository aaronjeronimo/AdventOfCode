#include <iostream>
#include <vector>
using namespace std;

int main() {
    int inicial[] = {3,3,2,1,4,1,1,2,3,1,1,2,1,2,1,1,1,1,1,1,4,1,1,5,2,1,1,2,1,1,1,3,5,1,5,5,1,1,1,1,3,1,1,3,2,1,1,1,
                     1,1,1,4,1,1,1,1,1,1,1,4,1,3,3,1,1,3,1,3,1,2,1,3,1,1,4,1,2,4,4,5,1,1,1,1,1,1,4,1,5,1,1,5,1,1,3,3,
                     1,3,2,5,2,4,1,4,1,2,4,5,1,1,5,1,1,1,4,1,1,5,2,1,1,5,1,1,1,5,1,1,1,1,1,3,1,5,3,2,1,1,2,2,1,2,1,1,
                     5,1,1,4,5,1,4,3,1,1,1,1,1,1,5,1,1,1,5,2,1,1,1,5,1,1,1,4,4,2,1,1,1,1,1,1,1,3,1,1,4,4,1,4,1,1,5,3,
                     1,1,1,5,2,2,4,2,1,1,3,1,5,5,1,1,1,4,1,5,1,1,1,4,3,3,3,1,3,1,5,1,4,2,1,1,5,1,1,1,5,5,1,1,2,1,1,1,
                     3,1,1,1,2,3,1,2,2,3,1,3,1,1,4,1,1,2,1,1,1,1,3,5,1,1,2,1,1,1,4,1,1,1,1,1,2,4,1,1,5,3,1,1,1,2,2,2,
                     1,5,1,3,5,3,1,1,4,1,1,4};
    //int inicial[] = {3,4,3,1,2};
    unsigned long long v[9] = {0};

    for (int i = 0; i < 300; i++)
        v[inicial[i]]++;

    unsigned long long total = 300;
    for (int i = 0; i < 256; i++) {
        unsigned long long anterior = total;
        total += v[0];

        unsigned long long aux = v[0];
        for (int j = 1; j < 9; j++)
            v[j-1] = v[j];
        v[6] += aux;

        v[8] = total - anterior;

        cout << fixed << i+1 << " -> " << total << endl;
    }

    cout << endl << total << endl;

    return 0;
}
