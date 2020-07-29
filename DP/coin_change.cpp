#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 
    dp[i] stores the number of ways to get the value i using a subset of coins from 
    coins array. Note that, we are counting the number of ways we can COMBINE a subset of 
    coins from coins array, not PERMUTE. For example, 4 = 1 + 3 = 3 + 1, we are considering
    both ways same.
    
    # But if we want to count the permutation, we need to interchange the order
    of the nested for loop. For all possible i, we need to traverse the whole coins array and
    count the number of ways. In this way, 4 = 1 + 3 = 3 + 1, both ways will be counted.
*/

ll coin_change(vector<ll> coins, ll target){
    vector<ll> dp(target + 1, 0);
    dp[0] = 1;
    for(int i=0;i<coins.size();i++){
        for(int j=coins[i];j<=target;j++){
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[target];
}

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> coins(m);
    for(int i=0;i<m;i++) cin >> coins[i];
    cout << coin_change(coins, n) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    ll tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}