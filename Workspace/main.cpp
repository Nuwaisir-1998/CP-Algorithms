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

#define MXS 300005

/********************************************************************/

vector<vector<ll>> adj(MXS);
vector<bool> in_scc(MXS);
vector<ll> tin(MXS), low(MXS);
ll timer;
vector<ll> scc;
ll scc_cnt;

void tarjan_scc(ll u){
    in_scc[u] = true;
    tin[u] = timer;
    low[u] = timer;
    scc.push_back(u);
    timer++;
    for(auto v : adj[u]){
        if(tin[v] == -1){
            tarjan_scc(v);
        }
        if(in_scc[v]){
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == tin[u]){
        while(true){
            ll p = scc.back();
            scc.pop_back();
            in_scc[p] = false;
            cout << p << " ";   // printing an scc
            if(u == p) break;
        }
        scc_cnt++;
        cout << endl;
    }
}

void find_sccs(ll n){ // 0 indexed
    timer = 0;
    scc_cnt = 0;
    scc.clear();
    in_scc.assign(n + 1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for(ll i=0;i<n;i++){
        if(tin[i] == -1){
            tarjan_scc(i);
        }
    }
}


void solve(ll cs){
    ll m, n, k, tt, i, j, l, x, y;
    cin >> n >> m;
    adj.clear();
    adj.resize(n+1);
    for(i=0;i<m;i++){
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);        // ATTENTION: We are considering directed graphs
    }
    find_sccs(n);
    // cout << scc_cnt << endl;
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
    ll cs = 1;
    while (tt--)
        solve(cs++);
    return 0;
}