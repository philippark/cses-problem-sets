#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void explore(vector<string>& map, int i, int j){
    map[i][j] = '#';

    for (int k = 0; k < 4; k++){
        int new_i = i + dirs[k][0];
        int new_j = j + dirs[k][1];

        if (new_i < 0 || new_i >= map.size() || new_j < 0 || new_j >= map[0].size()){
            continue;
        }

        if (map[new_i][new_j] == '.'){
            explore(map, new_i, new_j);
        }
    }
}

void solve(vector<string> &map) {
    int n = map.size();
    int m = map[0].size();
    int rooms = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (map[i][j] == '.'){
                explore(map, i, j);
                rooms++;
            }
        }
    }

    cout << rooms << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> map(n);

    for (auto &x : map){
        cin >> x;
    }

    solve(map);
}