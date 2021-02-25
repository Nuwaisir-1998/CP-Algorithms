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
void dbg(T x) {cerr << "x is " << x << '\n';}

#define MXS 600005

/********************************************************************/

ll count_odd_ones(ll x){
    return x / 2 + (__builtin_popcountll(x) % 2 == 0 and x % 2) + (__builtin_popcountll(x) % 2);
}

ll mod_mul(ll x, ll y, ll m){
    return ((x % m) * (y % m)) % m;
}

void solve(){
    ll n, m, i, j, k;
    cin >> n;
    vt<ll> odds(n), evens(n), cum_odds(n), cum_evens(n);
    for(ll i=0; i<n; i++){
        ll l, r;
        cin >> l >> r;
        odds[i] = (count_odd_ones(r) - count_odd_ones(l-1)) % MOD;
        evens[i] = (r - l + 1 - odds[i] + MOD) % MOD;
        if(i > 0) {
            cum_odds[i] = (cum_odds[i - 1] + odds[i]) % MOD;
            cum_evens[i] = (cum_evens[i - 1] + evens[i]) % MOD;
        }else {
            cum_odds[i] = odds[i];
            cum_evens[i] = evens[i];
        }
    }
    ll ans = 0;

    for(i=0;i<n-1;i++){
        ans = (ans + mod_mul(odds[i], cum_evens[n-1] - cum_evens[i] + MOD, MOD)) % MOD; 
        ans = (ans + mod_mul(evens[i], cum_odds[n-1] - cum_odds[i] + MOD, MOD)) % MOD;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("./in", "r", stdin);
    freopen("./out", "w", stdout);
#endif // ONLINE_JUDGE

    ll tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}