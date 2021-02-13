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


void solve(){
    ll n, m, q, i, j, k;
    cin >> n >> q >> k;
    vt<ll> v(n), opts(n), cum(n);
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    for(i=0;i<n;i++){
        if(i > 0 and i < n-1) opts[i] = v[i+1] - v[i-1] - 2;
    }
    opts[0] = v[0] - 2;
    opts[n-1] = k - v[n-1] - 1;
    cum[0] = opts[0];
    for(i=1;i<n;i++){
        cum[i] = cum[i-1] + opts[i];
    }
    // printv(opts);
    while(q--){
        ll l, r;
        cin >> l >> r;
        l--, r--;
        if(l == r){
            cout << k - 1 << endl;
            continue;
        }
        cout << max(0LL, cum[r-1] - cum[l]) + v[l+1] - 2 + k - v[r-1] - 1 << endl;
    }
    
    
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