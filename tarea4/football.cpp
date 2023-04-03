#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Game {
public:
    string enemyTeam;
    int scored, suffered;

    Game(string n, int sc, int su) {
        this->enemyTeam = n;
        this->scored = sc;
        this->suffered = su;
    }
};

class Team {
public:
    string name;
    vector<Game> games;
    int points, goalDiff, scored;

    Team(string n) {
        this->name = n;
    }

    void setStats() {
        int p = 0, sc = 0, su = 0;
        for (int i = 0; i < this->games.size(); i++) {
            Game g = games[i];
            if (g.scored > g.suffered) {
                p += 3;
            }
            else if (g.scored < g.suffered) {
                p++;
            }
            sc += g.scored;
            su += g.suffered;
        }
        this->points = p;
        this->scored = sc;
        this->goalDiff = sc - su;
    }
};

int lookTeam(vector<Team>& teams, string name) {
    int ans = 0;
    bool b = false;
    for (int i = 0; i < teams.size() && !b; i++) {
        if (teams[i].name == name) {
            ans = i;
            b = true;
        }
    }
    return ans;
}

bool custom(Team t1, Team t2) {
    bool ans = true;
    if (t1.points != t2.points) {
        ans = t1.points > t2.points;
    }
    else {
        if (t1.goalDiff != t2.goalDiff) {
            ans = t1.goalDiff > t2.goalDiff;
        }
        else {
            if (t1.scored != t2.scored) {
                ans = t1.scored > t2.scored;
            }
        }
    }
    return ans;
}

void solve(vector<Team> vt) {
    for (auto t : vt) {
        t.setStats();
    }

    sort(vt.begin(), vt.end(), custom);

    for (int i = 1; i <= vt.size(); i++) {
        printf("%d %16s ");
    }
}

void football() {
    int t, g;
    scanf_s("%d %d", &t, &g);
    while (t + g != 0) {
        vector<Team> vt;
        string tmp;
        for (int team = 0; team < t; team++) {
            cin >> tmp;
            Team tt(tmp);
            vt.push_back(tt);
        }
        string t1, t2;
        char sep;
        int s1, s2;

        for (int game = 0; game < g; game++) {
            cin >> t1 >> s1 >> sep >> s2 >> t2;
            int index = lookTeam(vt, t1);
            vt[index].games.push_back(Game(t2, s1, s2));
            index = lookTeam(vt, t2);
            vt[index].games.push_back(Game(t1, s2, s1));
        }
        solve(vt);
        scanf_s("%d %d", &t, &g);
    }

}