#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int numVagones;
    while (cin >> numVagones && numVagones) {
        int IDvagon;
        while (cin >> IDvagon && IDvagon) {
            /*
                COMPLEJIDAD: O(n)
                    - n = cantidad de vagones
            */
            stack<int> estacion;
            vector<int> caminoB(numVagones);
            caminoB[0] = IDvagon; // LIFO
            for (int i = 1; i < numVagones; i++) cin >> caminoB[i];
            
            int in = 1, out = 0;
            bool posible = true;
            while (out < numVagones && posible) {
                if (in == caminoB[out]) {
                    in++;
                    out++;
                } else if (!estacion.empty() && estacion.top() == caminoB[out]) {
                    estacion.pop();
                    out++;
                } else if (in <= numVagones) {
                    estacion.push(in++);
                } else {
                    posible = false;
                }
            }
            cout << (estacion.empty() ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
    return 0;
}