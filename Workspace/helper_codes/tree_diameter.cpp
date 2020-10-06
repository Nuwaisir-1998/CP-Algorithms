#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
#define all(x) (x).begin(), (x).end()
#define MOD 998244353
#define PI acos(-1)
#define MAXN 200005
#define INF 1000000000000000000

void printv(vector<ll> &v)
{
    for (auto e : v)
        cout << e << ' ';
    cout << "\n";
}

vector<ll> adj[MAXN];
vector<ll> g[MAXN];
vector<ll> vis(MAXN);
vector<ll> par(MAXN);
vector<bool> mark(MAXN);


pll dfs(ll u, ll p, ll val){
    par[u] = p;
    pll ret = {val, u};
    for(auto v : adj[u]){
        if(p == v) continue;
        ret = max(ret, dfs(v, u, val + 1));
    }
    return ret;
}

pll dfs2(ll u, ll val){
    mark[u] = true;
    pll ret = {val, u};
    for(auto v : adj[u]){
        if(mark[v]) continue;
        ret = max(ret, dfs2(v, val + 1));
    }
    return ret;
}


void solve(){
    ll n, i, j, u, v, k, l;
    cin >> n;
    for(i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pll t1 = dfs(1, -1, 0);
    pll t2 = dfs(t1.second, -1, 0);
    ll a = t1.second, b = t2.second;
    vector<ll> nodes;
    nodes.push_back(b);
    while(true){
        nodes.push_back(par[b]);
        b = par[b];
        if(par[b] == -1) break;
    }
    // printv(nodes);
    
    cout << "Number of nodes in the tree diameter:" << nodes.size() << "\n";
    cout << "And they are:\n";
    printv(nodes);
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
    while (tt--)
        solve();
    return 0;
}