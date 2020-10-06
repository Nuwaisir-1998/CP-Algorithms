#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void printv(vector<ll> & v) {for(auto ele : v) cout << ele << " "; cout << "\n";}

/*
    Idea : find all possible pairs of (x, y) such that x*x + y*y = n*n
    Then for each pair of (x, y) find the minimum number of coins to
    produce this (see coin change function for this).
*/

ll coin_change(vector<pair<ll,ll>> & coins, pair<ll,ll> target){
    vector<vector<ll>> dp(target.first + 1, vector<ll>(target.second+1, 0));
    dp[0][0] = 0;
    for(ll i=0;i<=target.first;i++){
        for(ll j=0;j<=target.second;j++){
            if(i == 0 and j == 0) continue;
            ll mn = INT_MAX;
            for(ll k=0;k<coins.size();k++){
                if(i - coins[k].first >= 0 and j - coins[k].second >= 0)
                    mn = min(mn, 1 + dp[i - coins[k].first][j - coins[k].second]);
            }
            dp[i][j] = mn;
        }
    }
    return dp[target.first][target.second];
}

bool solve() {
    ll n, m, i, j, x, y, target;
    cin >> n >> target;
    vector<pair<ll,ll>> coins;
    for(i=0;i<n;i++){
        cin >> x >> y;
        coins.push_back({x, y});
    }
    vector<pair<ll,ll>> answers;
    for(i=0;i<=target;i++){
        for(j=0;j<=target;j++){
            if(i*i + j*j == target*target){
                answers.push_back({i, j});
            }
        }
    }
    ll mn = INT_MAX;
    for(auto ele : answers){
        mn = min(mn, coin_change(coins, ele));
    }
    if(mn == INT_MAX) cout << "not possible\n";
    else cout << mn << "\n";
    return true;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif // ONLINE_JUDGE
    ll tt;
    cin >> tt;
    while(tt--){
        solve();
    }

}