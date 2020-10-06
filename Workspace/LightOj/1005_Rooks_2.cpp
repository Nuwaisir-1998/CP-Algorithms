#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/numeric>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define PI acos(-1)
#define MAXN 200005
#define INF 1000000000000000000
#define nl '\n'
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))

template <typename T>
void printv(vector<T> &v){for (auto e : v) cout << e << ' ';cout << '\n';}

struct custom_hash {
    // to make unordered map safe
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<ll, ll, custom_hash> safe_map;
gp_hash_table<ll, ll, custom_hash> safe_hash_table;

void solve(){
    ll n, m, i, j, k, x, y;
    vector<vector<ll>> nCr(31, vector<ll>(31,0));
    nCr[1][0] = 1;
    nCr[1][1] = 1;
    for(i=2;i<=30;i++){
        for(j=0;j<=i;j++){
            if(j == 0) nCr[i][j] = 1;
            else
                nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
            // cout << nCr[i][j] << " ";
        }
        // cout << "\n";
    }

    ll t;
    cin >> t;
    ll cs = 1;
    while(t--){
        cin >> n >> k;
        ll mul = 1;
        ll ans = 0;
        if(k <= n){ 
            for(i=2;i<=k;i++){
                mul *= i;
            }
            ans = nCr[n][k] * nCr[n][k] * mul;
        }
        // cout << nCr[n][k] << "\n";
        
        cout << "Case " << cs++ << ": " << ans << "\n";
        
    }
}

int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif // ONLINE_JUDGE

    ll tt = 1;
    // cin >> tt;
    // ll cs = 1;
    while (tt--)
        solve();
    
    return 0;
}