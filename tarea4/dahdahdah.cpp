/*
Nicolas Vidal
8950320

Complejidad: O(n) -> n = longitud de linea en caracteres
    - La funcion `find` tiene una complejidad temporal O(n)
    - El ciclo de mayor cantidad de iteraciones es de n

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dict(string s, vector<string> &codes, vector<string> &letters){
    
    vector<string>::iterator it = find(codes.begin(), codes.end(), s);
    string ans;
    if(it != codes.end()){
        cout << letters[it - codes.begin()];
    }
}

void split(string str){
    vector<string> codes = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."};
    
    vector<string> letters = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ",", "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "@"};
    string w = "";
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == ' '){
          if (i < str.length() - 1 && str[i-1] == ' '){
            cout << " ";
          }
            dict(w, codes, letters);
            w = "";
        }
        else {
            w = w + str[i];
        }
    }
    dict(w, codes, letters);
}

void dahdahdah() {
    int cases;
    cin >> cases;
    cin.ignore();
    string code;
    for (int c = 1; c <= cases; c++) {
        getline(cin, code);
        cout << "Message #" << c << "\n";
        split(code);
        cout << "\n\n";
    }
}

int main() {
    dahdahdah();
    return 0;
}