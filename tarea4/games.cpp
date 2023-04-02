#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void games() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> names(n);
        for (int i = 0; i < n; i++) {
            cin >> names[i];
        }

        sort(names.begin(), names.end());
        string low =  names[(n / 2)-1];
        string high = names[(n / 2)];
        string a;
        bool b = true;
        for (size_t ind = 0; ind < low.length() && ind < high.length() && b; ind++) {
            if (low[ind] == high[ind]) {
                a += low[ind];
            }
            else {
                a += int(low[ind])+1;
                b = !b;
            }
        }
        cout << a << endl;
    }
}


int main() {
    games();
    return 1;
}