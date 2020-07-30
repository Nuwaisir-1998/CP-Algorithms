#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> dp(30002, 0);
ll coin_change(vector<ll> coins, ll target){
    dp[0] = 1;
    for(ll i=0;i<coins.size();i++){
        for(ll j=coins[i];j<=target; j++){
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[target];
}

bool solve(){
    double d;
    cin >> d;
    if(d == 0) return false;
    ll n = (ll)((d + 0.001) * 100);
    ll ans = dp[n];
    printf("%6.2f%17lld\n", d, ans);
    return true; // Without this line, there wass an RTE.
}

int main(){
    // ios::sync_with_stdio(false);
// #ifndef ONLINE_JUDGE
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
// #endif // ONLINE_JUDGE
    vector<ll> coins = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    coin_change(coins, 30000);
    while(solve());
    
    return 0;
}