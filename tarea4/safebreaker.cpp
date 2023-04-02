/*
Nicolas Vidal
8950320

Complejidad: 
    = TOTAL_COMBINATIONS * num_guesses * 10 
    = O(Digitos_en_codigo * num_guesses * digitos_0_9)

    - En la funcion `safebreaker` el for principal hace 10 mil iteraciones.
      Este numero es el resultado de multiplicar la cantidad de digitos posibles (0-9)
      por la cantidad de digitos que hay en el codigo = 4: 0 0 0 0 -> 9 9 9 9
    - Dentro de esta funcion se hace un llamado por iteracion a la funcion `consistent`,
      la cual tiene un ciclo que itera sobre la cantidad total de inputs (intentos U pistas).
    - Dentro de la funcion `cosistent` se hace un llamado por iteraciona la funcion
      `count_digits`, la cual contiene un ciclo que itera 10 veces (la cantidad de digitos
      del 0 -> 9).
    - Todos estos procesos se realizan dentro del otro, a eso se debe la multiplicacion
      en la expresion de complejidad temporal.
      
Referencias:

to_string = 
  https://www.simplilearn.com/tutorials/cpp-tutorial/int-to-string-cpp

Convert char to int = 
  https://www.geeksforgeeks.org/cpp-program-for-char-to-int-conversion/

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


pair<int, int> count_digits(string code, string guess) {
    const int MAX_CHARACTERS = 10;
    int correct = 0, misplaced = 0;
    int char_index, guess_index;
    vector<int> char_count(MAX_CHARACTERS), guess_counts(MAX_CHARACTERS);
    for (int i = 0; i < code.size(); i++) {
        if (code[i] == guess[i]) {
            correct++;
        }
        char_index = (int)code[i] - 48; // Convert char -> int: ASCII(0) = 48
        guess_index = (int)guess[i] - 48;
        char_count[char_index]++; 
        guess_counts[guess_index]++;
    }
    for (int digit = 0; digit < 10; digit++) {
        misplaced += min(char_count[digit], guess_counts[digit]);
    }
    misplaced -= correct;
    return make_pair(correct, misplaced);
}

bool consistent(string code, vector<pair<string, pair<int, int>>> guesses) {
    bool ans = false;
    for (size_t i = 0; i < guesses.size() && !ans; i++) {
        string guess_code = guesses[i].first;
        pair<int, int> clue = guesses[i].second;
        pair<int, int> count = count_digits(code, guess_code);
        if (count != clue) {
            ans = !ans;
        }
    }
    return ans;
}

void safebraker() {
    const int TOTAL_COMBINATIONS = 10 * 10 * 10 * 10;
    int num_cases;
    cin >> num_cases;
    while (num_cases--) {
        int num_guesses;
        cin >> num_guesses;
        vector<pair<string, pair<int, int>>> guesses(num_guesses);
        for (int i = 0; i < num_guesses; i++) {
            string code;
            char sep;
            int correct, misplaced;
            cin >> code >> correct >> sep >> misplaced;
            guesses[i] = make_pair(code, make_pair(correct, misplaced));
        }
        vector<string> possible_codes;
        for (int i = 0; i < TOTAL_COMBINATIONS; i++) {
            string code = to_string(i);
            while (code.length() < 4) {
                code = '0' + code;
            }
            if (consistent(code, guesses)) {
                possible_codes.push_back(code);
            }
        }
        if (possible_codes.empty()) {
            cout << "impossible\n";
        }
        else if (possible_codes.size() == 1) {
            cout << possible_codes[0] << '\n';
        }
        else {
            cout << "indeterminate\n";
        }
    }
}

int main() {
    safebraker();
    return 0;
}
