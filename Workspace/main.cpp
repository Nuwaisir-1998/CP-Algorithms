#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/numeric>

// #include <atcoder/all>
// using namespace atcoder;

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


void solve(ll cs){
    ll n, m, i, j, k;
    cin >> n;
    vt<ll> v(n);
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    ll mn = INF;
    for(ll dif=1;dif<=n-1;dif++){
        vt<ll> bebodhan;
        for(j=0;j + dif < n;j++){
            bebodhan.push_back(v[j + dif] - v[j]);
        }
        m = bebodhan.size();
        vt<bool> mark(m, false);
        k = 0;
        ll mx = 0;
        for(j=0;j<m;j++){
            ll cnt = 0;
            k = j;
            if(mark[j]) continue;
            while(k < m and bebodhan[k] == bebodhan[j]){
                mark[k] = true;
                k += dif;
                cnt++;
            }
            mx = max(mx, cnt);
        }
        // cout << dif << " " << mx << endl;
        // printv(bebodhan);
        mn = min(mn, n - mx - 1);
    }

    cout << mn << endl;
}

int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("./in", "r", stdin);
    // freopen("./out", "w", stdout);
#endif // ONLINE_JUDGE

    ll tt = 1, cs = 1;
    cin >> tt;
    while (tt--)
        solve(cs++);
    return 0;
}