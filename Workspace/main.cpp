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
    ll n, m, i, j, k, x, y;
    cin >> n >> k >> m;
    vll v(n), cum(n);
    ll sum = 0, sz = n;
    for(ll i=0; i<n; i++){
        cin >> v[i];
    }

    sort(all(v));
    for(i=0;i<n;i++){
        if(i == 0) cum[i] = v[i];
        else cum[i] = v[i] + cum[i-1];
    }
    double mx = 0;
    for(i=0;i<=min(m, n-1);i++){
        sz = n - i;
        sum = cum[n - 1] - cum[i] + v[i];
        ll left_ops = m - i;
        sum += min(sz * k, left_ops);
        mx = max(mx, sum * 1.0 / sz);
    }

    cout << fixed << setprecision(10) << mx << endl;
    
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