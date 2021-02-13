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
    ll n, m, i, j, k;
    cin >> n >> m;
    vt<vt<ll>> v(n, vt<ll>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if((i + j) % 2 == 0){
                cout << 720720 << " ";
            }else{
                ll mul = 1;
                k = 4;
                while(k--) mul *= v[i][j];
                if(v[i][j] == 16) mul = 16;
                cout << 720720 + mul << " ";
            }
        }
        cout << endl;
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