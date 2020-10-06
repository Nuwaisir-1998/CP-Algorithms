#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000

void printv(vector<ll> & v) {for(auto ele : v) cout << ele << " "; cout << "\n";}

/*
    ALERT : This solution has higher space complexity, can be improved.
*/

void coin_change(vector<ll> coins, ll target){
    vector<vector<ll>> dp(105, vector<ll> (20005, INF));
    vector<ll> possibles;

    dp[0][0] = 0;
    dp[0][coins[0]] = 1;
    possibles.push_back(coins[0]);
    
    for(ll i=1;i<coins.size();i++){
        for(ll j=0;j<=20000;j++){
            if(j == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            if(j >= coins[i])
                dp[i][j] = min(dp[i][j], 1 + dp[i-1][j - coins[i]]);
            if(dp[i][j] != INF) possibles.push_back(j);
        }
    }

    sort(possibles.begin(), possibles.end());
    // printv(possibles);
    ll idx = lower_bound(possibles.begin(), possibles.end(), target) - possibles.begin();
    cout << possibles[idx] << " " << dp[coins.size()-1][possibles[idx]] << "\n";
}

void solve(){
    ll target, n, i, j, k;
    cin >> target;
    cin >> n;
    vector<ll> coins(n);
    for(i=0;i<n;i++){
        cin >> coins[i];
    }
    coin_change(coins, target);
}

int main(){
    // ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // ONLINE_JUDGE
    int tt; 
    cin >> tt;
    while(tt--){
        solve();
    }

}