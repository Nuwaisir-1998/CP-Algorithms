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

#define MXS 10005

/********************************************************************/

vector<vector<ll>> adj(MXS);
vector<bool> vis(MXS), tin(MXS), low(MXS);
vector<ll> articulation_points;
vector<pll> articulation_bridges;
ll timer;

void dfs(ll u, ll par = -1){
    vis[u] = true;
    tin[u] = timer;
    low[u] = timer;
    timer++;
    // cout << timer << endl;
    ll child_count = 0;
    for(auto v : adj[u]){
        if(v == par) continue;
        if(!vis[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= tin[u] and par != -1){
                articulation_points.push_back(u);
            }
            if(low[v] > tin[u]){
                articulation_bridges.push_back({u, v});
            }
            child_count++;
        }else{
            low[u] = min(low[u], tin[v]);
        }
    }
    if(par == -1 and child_count > 1){
        articulation_points.push_back(u);
    }
}

void find_articulation_points_and_bridges(){
    timer = 0;
    articulation_points.clear();
    articulation_bridges.clear();
    vis.assign(MXS, false);
    tin.assign(MXS, -1);
    low.assign(MXS, -1);
    for(ll i=0;i<MXS;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
}


void solve(ll cs){
    ll m, n, k, tt, i, j, l, x, y;
    while(true){
        cin >> n >> m;
        if(n == 0){
            return;
        }
        adj.clear();
        adj.resize(n+3);
        for(i=0;i<m;i++){
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        // for(i=0;i<n;i++){
        //     cout << i << ": ";
        //     printv(adj[i]);
        // }
        find_articulation_points_and_bridges();
        for(i=0;i<n;i++) {
            cout << low[i] << " " << tin[i] << endl;
        }
        cout << articulation_points.size() << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif // ONLINE_JUDGE
    ll tt = 1;
    // cin >> tt;
    ll cs = 1;
    while (tt--)
        solve(cs++);
    return 0;
}