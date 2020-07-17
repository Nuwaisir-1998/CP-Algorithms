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
vector<double> cost[MAXN];
vector<pll> coord(MAXN);

double computeCost(ll x, ll y){
    return sqrt(1.0 * (coord[x].first - coord[y].first) * (coord[x].first - coord[y].first) + (coord[x].second - coord[y].second) * (coord[x].second - coord[y].second) * 1.0);
}

class DSU{ // 0 indexed
    ll numSets;
    vll rank, p, setSize;
public:
    DSU(int n){
        setSize.assign(n, 1);
        rank.assign(n,0);
        p.assign(n,0);
        for(ll i=0;i<n;i++) p[i] = i;
        numSets = n;
    }
    int findSet(ll i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(ll i, ll j){
        return findSet(i) == findSet(j);
    }
    void unionSet(ll i, ll j){
        if(!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i);
            int y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x;
                setSize[x] += setSize[y];
            }else{
                p[x] = y;
                if(rank[x] == rank[y]){
                    rank[y]++;
                }
                setSize[y] += setSize[x];
            }
        }
    }

    int numDisjointSets(){
        return numSets;
    }

    int sizeOfSet(ll i){
        return setSize[findSet(i)];
    }
};

// Here, we are considering there are edges among all the vertices.

double kruskal(ll n){
    ll i, j, k;
    double min_cost = 0;
    set<pair<double, pll>> pq;
//    set<ll> vertices;
    DSU vertices(n);
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
//            cout << i << ' ' << j << ' ' <<  computeCost(i, j) << "\n";
            pq.insert(make_pair(computeCost(i, j), make_pair(i, j)));
        }
    }
    set<pair<double, pll>> :: iterator itr;
    ll edge_cnt = 0;
    while(edge_cnt != n-1){
        itr = pq.begin();
        double weight = itr -> first;
        pll nodes = itr -> second;
//        cout << nodes.first << " " << nodes.second << " " << weight << '\n';
        pq.erase(itr);
//        edge_cnt++;
        if(!vertices.isSameSet(nodes.first-1, nodes.second-1)){
            vertices.unionSet(nodes.first-1, nodes.second-1);
//            cout << "nisi : " << nodes.first << " " << nodes.second << " " << weight << '\n';
            min_cost += weight;
            edge_cnt++;
        }
    }
    return min_cost;
}

void solve() {
    ll m, p, i, y, j = 0, c, x, t, q, b, n;
    cin >> n;
    vector<pll> v(n);
    for(i=1;i<=n;i++){
        cin >> x >> y;
        coord[i].first = x;
        coord[i].second = y;
    }
    cout << fixed << setprecision(9) << kruskal(n) << "\n";

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