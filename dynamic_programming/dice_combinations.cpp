#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


/*
if current is <= 6, +1
+1 for each possibility from prev possible dice throws.

3

1,2,4


[i] += [i-prev] where 1<=prev<=6

if i <= 6: [i]++
*/



void solve(int n) {
    vector<int> dp(n);

    for (int i = 0; i < n; i++){
        if (i < 6){
            dp[i]++;
        }

        for (int j = 1; j <= 6; j++){
            if (i-j < 0) break;
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }

    cout << dp[n-1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    solve(n);
}