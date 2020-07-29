#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Problem Link: https://codeforces.com/contest/1382/problem/D
*/

void printv(vector<ll> & v){
    for(auto ele : v) cout << ele << " "; cout << "\n";
}


// Here, we consider coins are limited, not infinite.

ll coin_change(vector<ll> & coins, ll target){
    vector<vector<ll>> dp(coins.size()+1, vector<ll>(4000+5, 0));
    dp[0][0] = 1;
    dp[0][coins[0]] = 1;
    for(ll i=1;i<coins.size();i++) {
        for(ll j=0;j<=target;j++){
            if(j == 0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            if(j - coins[i] >= 0)
                dp[i][j] |= dp[i-1][j - coins[i]];
        }
    }
    return dp[coins.size() - 1][target];
}

void solve()
{
    ll n, i, m, j;
    cin >> n;
    n *= 2;
    vector<ll> v(n);
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    ll mx = v[0];
    ll cnt = 1;
    ll sum = 0;
    vector<ll> vals;
    for(i=1;i<n;i++){
        if(v[i] > mx) {
            mx = v[i];
            vals.push_back(cnt);
            sum += cnt;
            cnt = 1;
        }else cnt++;
    }
    vals.push_back(cnt);
    sum += cnt;
    if(coin_change(vals, n / 2)){
        cout << "YES\n";
    }else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    ll tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
