#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> deconstruct(string& word) {
    /*
    COMPLEJIDAD: a log(n)
        - a = caracteres dentro de la palabra
        - n = cantidad de elementos dentro del mapa
    */
    map<char, int> m;
    for (char c : word) {
        if (c != ' ') {
            if (m.count(c)) {
                m[c]++;
            }
            else {
                m.insert({ c,1 });
            }
        }
    }
    return m;
}

int compare(vector<map<char, int>>& d, map<char, int>& m) {
    int count = 0;
    for (int i = 0; i < d.size(); i++) {
        bool b = true;
        map<char, int> a = d[i];
        for (map<char, int>::iterator it = d[i].begin(); it != d[i].end() && b; it++) {
            char obj_char = it->first;
            int asked = it->second;
            int available;
            if (m.count(it->first)) {
                available = m.at(it->first);
            }
            if (!m.count(it->first) || m.at(it->first) < it->second) {
                b = false;
            }
        }
        if (b) count++;
    }
    return count;
}

int main() {
    vector<map<char, int>> dictionary;
    string word;
    while (cin >> word && word != "#") {
        sort(word.begin(), word.end());
        dictionary.push_back(deconstruct(word));
    }

    string line;
    getline(cin, line);
    while (getline(cin, line) && line != "#") {
        /*
            COMPLEJIDAD: a*b*log(c)
                a = # palabras dentro del diccionario
                b = # caracteres unicos de cada palabra
                c = # caracteres unicos propuestos (segundo input)       
        */
        map<char, int> letters;
        sort(line.begin(), line.end());
        letters = deconstruct(line);
        cout << compare(dictionary, letters) << endl;
    }

    return 0;
}
