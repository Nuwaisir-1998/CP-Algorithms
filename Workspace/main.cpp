#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/numeric>
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define ordered_set tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update>
 
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define MOD9 998244353
#define PI acos(-1)
#define MAXN 500005
#define INF 100000000000000000
#define nl '\n'
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define ff first
#define ss second
#define vt vector
#define FOR(n) for(i=0;i<n;i++)

template <typename T>
void printv(vector<T> &v, ll add){for (auto e : v) cout << e + add << ' ';cout << '\n';}
template <typename T>
void printv(vector<T> &v){for (auto e : v) cout << e << ' ';cout << '\n';}
template <typename T>
void printst(set<T> &v){for (auto e : v) cout << e << ' ';cout << '\n';}
template <typename T>
void printst(set<T> &v, ll add){for (auto e : v) cout << e + add << ' ';cout << '\n';}
template <typename T>
void dbg(T x) {cerr << "x is " << x << '\n';}

struct custom_hash {
    // to make unordered map safe
    static uint64_t splitmix64(uint64_t x) {
        // http://xor_shift.di.unimi.it/splitmix64.c
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

#define MXS 500005

/********************************************************************/

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
vt<ll> fact(2005, 1), inv(2005, 1);

ll mod_mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}


void solve(){
    ll i, j, n, m, k, x;
    cin >> n;
    vt<string> v(n), t(n);

    for(i=0;i<n;i++) cin >> v[i];
    for(i=0;i<n;i++) cin >> t[i];
    
    for(j=0;j<n;j++){
        if(v[0][j] != t[0][j]){
            for(i=0;i<n;i++){
                if(v[i][j] == '0') v[i][j] = '1'; 
                else v[i][j] = '0';
            }
        }
    }

    for(i=1;i<n;i++){
        for(j=0;j<n;j++){
            if(v[i][j] != t[i][j]){
                for(k=0;k<n;k++) {
                    if(v[i][k] == '0') v[i][k] = '1';
                    else v[i][k] = '0';
                }
                break;
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(v[i][j] != t[i][j]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}


int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif // ONLINE_JUDGE

    for(ll i=1;i<2005;i++) fact[i] = (fact[i-1] * i) % MOD;
    for(ll i=1;i<2005;i++) inv[i] = (inv[i-1] * bigmod(i, MOD-2, MOD)) % MOD;

    ll tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}