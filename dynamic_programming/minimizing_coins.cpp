#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve(vector<int>& coins, int target) {
    vector<int> dp(target+1, INT_MAX);

    for (int i = 1; i <= target; i++){
        for (int j = 0; j < coins.size(); j++){
            if (i == coins[j]){
                dp[i] = 1;
            }
            if (i-coins[j] >= 1 && dp[i-coins[j]] != INT_MAX){
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    if (dp[target] == INT_MAX){
        cout << -1 << "\n";
    }
    else {   
        cout << dp[target] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto &x : coins){
        cin >> x;
    }

    solve(coins, x);
}