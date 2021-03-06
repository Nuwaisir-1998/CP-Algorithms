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
#define ff first
#define ss second
#define vt vector
#define FOR(n) for(i=0;i<n;i++)
 
template <typename T>
void printv(vector<T> &v){for (auto e : v) cout << e << ' ';cout << '\n';}
template <typename T>
void dbg(T x) {cerr << "x is " << x << '\n';}

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

/********************************************************************/

vector<vector<ll>> adj;
vector<vector<ll>> weight;
vector<ll> dist;
vector<ll> par;

void dijkstra(ll s){
    ll n = adj.size();
    vector<bool> vis(n, false);
    dist.resize(n, INF);
    par.resize(n, -1);
    // printv(par);
    dist[s] = 0;
    set<pll> st;
    st.insert({0, s});
    while(!st.empty()){
        // for(auto ele : st) cout << "{" << ele.first << " " << ele.second << "}\n";
        pll pu = *st.begin();
        ll u = pu.second;
        st.erase(st.begin());
        vis[u] = true;
        // cout << u << " : u\n";
        // printv(adj[u]);
        ll i = 0;
        for(auto ele : adj[u]){
            // cout << ele << " : ele\n";
            if(dist[u] + weight[u][i] < dist[ele]){
                st.erase({dist[ele], ele});
                dist[ele] = dist[u] + weight[u][i];
                par[ele] = u;
                st.insert({dist[ele], ele});
            }
            i++;
        }
    }
    // printv(par);
}

void solve(ll cs){
    ll i, j, k, l, n, m, x, y, z;
    cin >> n >> m;
    adj.resize(n);
    weight.resize(n);
    for(i=0;i<m;i++){
        cin >> x >> y >> z;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        weight[x].push_back(z);
        weight[y].push_back(z);
    }
    dijkstra(0);
    if(dist[n-1] == INF) cout << -1 << "\n";
    else{
        i = n-1;
        vector<ll> ans;
        while(par[i] != -1){
            ans.push_back(i+1);
            i = par[i];
        }
        ans.push_back(i+1);
        reverse(all(ans));
        printv(ans);
    }
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