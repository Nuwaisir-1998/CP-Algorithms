#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
#define all(x) (x).begin(), (x).end()
#define MOD 998244353
#define PI acos(-1)
#define MAXN 200005

void printv(vector<ll> &v){ for(auto e : v) cout << e << ' ';cout << "\n";}

vector<ll> adj[100005];
vector<ll> cost[100005];
vector<bool> vis(100005);
vector<ll> dist(100005, LONG_LONG_MAX);

bool dijkstra(ll source){
    set<pll> :: iterator itr;
    set<pll> pq;
    pq.insert({0, source});
    dist[source] = 0;
    while(!pq.empty()){
        itr = pq.begin();
        ll u = itr -> second;
        vis[u] = true;
        pq.erase(itr);
        for(int i=0;i<adj[u].size();i++) {
            ll v = adj[u][i];
            ll prevCost = dist[v];
            dist[v] = min(dist[v], dist[u] + cost[u][i]);
            if(pq.find({prevCost, v}) != pq.end()) pq.erase(pq.find({prevCost, v}));
            if(!vis[v]) pq.insert({dist[v], v});
        }
    }
    return true;
}

void solve() {
    ll m, p, i, y, j = 0, c, x, t, q, b, n;
    cin >> n >> m;
    for(i=0;i<m;i++){
        cin >> x >> y >> c;
        adj[x].push_back(y);
        cost[x].push_back(c);
    }
    ll u, v;
    cin >> u >> v;
    dijkstra(u);
    cout << (dist[v] == LONG_LONG_MAX ? -1 : dist[v]) << "\n";

}


int main() {
    ios::sync_with_stdio(false);
//#ifndef ONLINE_JUDGE
//    freopen("E:\\CP_Stuffs\\UVA\\in", "r", stdin);
//    freopen("E:\\CP_Stuffs\\UVA\\out", "w", stdout);
//#endif // ONLINE_JUDGE
    ll tt = 1;
//    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}