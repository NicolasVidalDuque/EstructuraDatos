#include <iostream>
#include <list>
#include <map>
#include <utility>

using namespace std;

void print(list<pair<int, int>> &l){
    for(auto a : l){
        cout << a.first << " " << a.second << endl;
    }
}

int main(){
    /* 
        COMPLEJIDAD:

        Si se realizan muchos comandos "E" seguidos -> n
            - n = cantidad de comandos "E" realizados seguidos del mismo id
        
        De lo contrario -> log(c)
            - c = cantidad de ordenes 
                - esto traduce a la longitud del mapa

    */
    int p;
    int c;
    int count = 1;
    char command;
    while(cin >> p >> c && c+p != 0){
        cout << "Case " << count++ << ":" << endl;
        list<pair<int, int>> l;
        map<int, int> m;
        int u = c > p ? p : c;
        for(int i = 1; i <= u; i++){
            l.push_back({i,0}); // O(1)
            m.insert({i,0}); // log(n)
        }
        for(int i = 0; i < c; i++){
            cin >> command;
            if (command == 'E'){
                int id;
                cin >> id;
                if(!m.count(id)){ // log(n)
                    m.insert({id,0}); // log(n)
                }
                m[id]++;
                l.push_front({id,m[id]}); // O(1)
            }else{
                bool b = false;
                while(!b){
                    int id = l.front().first;
                    if(l.front().second == m[id]){
                        cout << id << endl;
                        l.push_back({id, m[id]});
                        b = true;
                    }
                    l.pop_front();
                }
            }
        }

    }
    return 0;
}