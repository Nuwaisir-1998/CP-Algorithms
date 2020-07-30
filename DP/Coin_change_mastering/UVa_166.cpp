#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void printv(vector<ll> & v) {for(auto ele : v) cout << ele << " "; cout << "\n";}

ll coin_change(vector<ll> & coins, ll sum, ll target){
    vector<ll> dp(sum+5, 0);
    dp[0] = 0;
    for(ll i=1;i<=sum;i++){
        ll mn = INT_MAX;
        for(ll j=0;j<coins.size();j++){
            if(i - coins[j] >= 0)
                mn = min(1 + dp[i - coins[j]], mn);
        }
        dp[i] = mn;
    }
    vector<ll> all_coins = {5, 10, 20, 50, 100, 200};
    for(ll i=sum;i>=0;i--){
        if(dp[i] == INT_MAX) continue;
        for(ll j=0;all_coins[j];j++){
            if(i - all_coins[j] >= 0)
                dp[i - all_coins[j]] = min(dp[i - all_coins[j]], dp[i] + 1);
        }
    }
    return dp[target];
}

bool solve() {
    ll n, m, i, j;
    double d;
    vector<ll> v(6);
    vector<ll> coinValues = {5, 10, 20, 50, 100, 200};
    vector<ll> coins;
    unordered_map<ll, ll> ump;
    bool exists = false;
    ll sum = 0;
    for(i=0;i<6;i++){
        cin >> v[i];
        sum += v[i] * coinValues[i];
        for(j=1;j<=v[i];j++) {
            coins.push_back(coinValues[i]);
            ump[coinValues[i]] = v[i];
        }
        if(v[i] != 0) exists = true;
    }
    cin >> d;
    ll target = (ll)((d + 0.001) * 100);

    if(!exists) return false;
    
    printf("%3lld\n", coin_change(coins, sum, target));
    return true;
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
// #endif // ONLINE_JUDGE
    while(solve());
    // cout << "3\n";

}