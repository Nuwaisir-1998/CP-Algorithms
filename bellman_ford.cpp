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
#define INF 1000000000000000000

void printv(vector<ll> &v){ for(auto e : v) cout << e << ' ';cout << "\n";}

vector<ll> adj[MAXN];
vector<ll> cost[MAXN];
vector<ll> negInf(MAXN, false);
vector<ll> dist(MAXN, INF);

// Returns true if negative cycle exists, 
// This code may needs to be updated for working with a graph having more than
// one component.

bool bellmanFord(ll n, ll source){
    bool negCyc = false;
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=n;j++) {
            if(dist[j] == INF) continue;
            for(int k=0;k<adj[j].size();k++){
                ll v = adj[j][k];
                if(i >= n and dist[j] + cost[j][k] < dist[v]) {
                    // negative cycle exists
                    negInf[v] = true;
                    negCyc = true;
                }
                if(dist[j] + cost[j][k] < dist[v]) {
                    dist[v] = dist[j] + cost[j][k];
                }
                if(negInf[j]) negInf[v] = true;
            }
        }
    }
    return negCyc;
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
    cin >> u;
    bool paisi = false;
    for(i=0;i<adj[u].size();i++){
        if(adj[u][i] == u){
            dist[u] = cost[u][i];
            paisi = true;
            break;
        }
    }
    if(!paisi) dist[u] = 0;
    bellmanFord(n, u);
    for(i=1;i<=n;i++){
        ll ele = dist[i];
        if(negInf[i]){
            cout << '-' << "\n";
        }else if(ele == INF){
            cout << '*' << "\n";
        }
        else cout << ele << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
//#ifndef ONLINE_JUDGE
//    freopen("E:\\CP_Stuffs\\UVA\\in", "r", stdin);
//    freopen("E:\\CP_Stuffs\\UVA\\out", "w", stdout);
//#endif // ONLINE_JUDGE
    ll tt = 1;
//    cin >> tt;
    while (tt--) solve();
    return 0;
}