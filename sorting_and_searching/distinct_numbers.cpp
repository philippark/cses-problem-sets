#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto &x : a){
        cin >> x;
    }

    sort(a.begin(), a.end());

    int distincts = 1;

    for (int i = 1; i < n; i++){
        distincts += a[i] != a[i-1];
    }

    cout << distincts << "\n";
}