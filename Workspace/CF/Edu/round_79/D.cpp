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
#define MOD9 998244353
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

ll bigmod ( ll a, ll p, ll m )
{
    ll res = 1;
    ll x = a;
    while (p)
    {
        if (p & 1) //p is odd
        {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        p = p >> 1;
    }
    return res;
}


void solve(){
    ll n, m, k, i, j, x;
    cin >> n;
    vector<ll> occurs(1000002, 0);
    vector<ll> adj[n];
    for(i=0;i<n;i++){
        cin >> k ;
        for(j=0;j<k;j++){
            cin >> x;
            adj[i].push_back(x);
            occurs[x]++;
        }
    }
    ll ans = 0;
    for(i=0;i<n;i++){
        // ans += (bigmod(n, MOD9-2, MOD9)) % MOD9;
        for(auto ele : adj[i]){
            // cout << "(1 / " << n << " )" << "\n";
            ll mul = (bigmod(n, MOD9-2, MOD9)) % MOD9;
            // cout << "(1 / " << adj[i].size() << " )" << "\n";
            mul = (mul * bigmod(adj[i].size(), MOD9-2, MOD9)) % MOD9;
            // cout << "mul * " << occurs[ele] << '\n';
            mul = (mul * occurs[ele]) % MOD9;
            // cout << "(1 / " << n << " ) " <<'\n';
            mul = (mul * bigmod(n, MOD9 - 2, MOD9)) % MOD9;
            // cout << "added\n";
            ans = (ans + mul) % MOD9;
        }
    }

    cout << ans  << "\n";

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