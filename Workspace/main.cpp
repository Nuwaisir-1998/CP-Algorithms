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

#define MXS 600005

/********************************************************************/

void solve(){
    ll n, m, i, j, k;
    cin >> n >> m;
    vt<vt<ll>> adj(n+1);
    vt<vt<ll>> cost(n+1,vt<ll>(n+1));
    vt<set<char>> vst(n+1); 
    vt<set<char>> vst_ber(n+1); 
    for(i=0;i<n;i++){
        string s;
        for(j=0;j<n;j++){
            if(i != j){
                cost[i][j] = s[j];
                adj[i].push_back(j);
                vst[j].insert(s[j]);
                vst[i].insert(s[j]);
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i != j){
                if(cost[i][j] == cost[j][i]){
                    cout << "YES" << endl;
                    ll par = 0;
                    while(m--){
                        if(par % 2){
                            cout << i+1 << " ";
                        }else cout << j + 1 << " ";
                        par++;
                    }
                    return;
                }
            }
        }
    }
    vt<vt<ll>> vis(n+1, vt<ll> (n+1, 0));
    


}

int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif // ONLINE_JUDGE

    ll tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}