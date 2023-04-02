/*
Nicolas Vidal
Codigo: 895320

Complejidad: O(G*P) donde G es el numero de carreras y P es el numero de pilotos
    - Esto se debe a que dentro de la solucion hay un for_g dentro de un for_p
    - Esta anidacion es la linea de codigo que mas se repite, por lo tante es la que marca el tope de la complejidad
    - La operacion `sort` tiene una complejidad O(w log(w)) -> w = winners, no obstante se esta organizando el vector de ganadores,
      lo que implica que es muy poco probable que sean todos los pilotos P. (se puede decir que es amortiguado?) 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int formula() {
    const int MAX_G = 100;
    const int MAX_P = 500;
    int G, P;
    while (cin >> G >> P, G && P) {
        int position[MAX_G][MAX_P] = {};
        for (int i = 0; i < G; i++) {
            // RESULT OF RACE
            int pos;
            for (int j = 0; j < P; j++) {
                cin >> pos;
                position[i][j] = pos;
            }
        }
        int S;
        cin >> S;
        while (S--) {
            int K, score[MAX_P] = { 0 };
            cin >> K;
            for (int i = 0; i < K; i++) {
                cin >> score[i];
            }
            // SOLUTION
            int max_points = 0;
            vector<int> winners;
            int pilotScore[MAX_P] = {};
            for (int p = 0; p < P; p++) {
                for (int g = 0; g < G; g++) {
                    pilotScore[p] += score[position[g][p] - 1];
                }
                if (pilotScore[p] > max_points) {
                    max_points = pilotScore[p];
                    winners.clear();
                    winners.push_back(p + 1);
                }
                else if (pilotScore[p] == max_points) {
                    winners.push_back(p + 1);
                }
            }
            sort(winners.begin(), winners.end());
            for (size_t winner = 0; winner < winners.size(); winner++) {
                string s = winner == winners.size()-1 ? "\n": " ";
                cout << winners[winner] << s;
            }
        }
        
    }
    return 0;
}

int main() {
    formula();
    return 0;
}