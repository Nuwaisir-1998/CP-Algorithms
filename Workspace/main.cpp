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

#define MXS 100005

/********************************************************************/


class DSU{
    ll numSets;
    vll rank, p, setSize;
public:
    DSU(ll n){
        setSize.assign(n, 1);
        rank.assign(n,0);
        p.assign(n,0);
        for(ll i=0;i<n;i++) p[i] = i;
        numSets = n;
    }
    ll findSet(ll i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(ll i, ll j){
        return findSet(i) == findSet(j);
    }
    void unionSet(ll i, ll j){
        if(!isSameSet(i, j))
        {
            numSets--;
            ll x = findSet(i);
            ll y = findSet(j);
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

    ll numDisjollSets(){
        return numSets;
    }

    ll sizeOfSet(ll i){
        return setSize[findSet(i)];
    }
};
void solve(){
    ll n, m, i, j, k, b, a, c, q;
    cin >> n >> m;
    vt<ll> vx(m), vy(m), ops(m, 2);
    vt<ll> mark(n, 0);
    vt<ll> row(n, -1), col(n, -1);
    for(i=0;i<m;i++){
        cin >> vx[i] >> vy[i];
        vx[i]--, vy[i]--;
        mark[vx[i]]++;
        mark[vy[i]]++;
        row[vx[i]] = i;
        col[vy[i]] = i;
    }
    DSU dsu(m);

    for(i=0;i<n;i++){
        // cout << row[i] << " " << col[i] << endl;
        if(row[i] != -1 and col[i] != -1)
            dsu.unionSet(row[i], col[i]);
    }
    // return;

    vt<vt<ll>> adj(m);

    for(i=0;i<m;i++){
        if(mark[vx[i]] <= 1 or mark[vy[i]] <= 1){
            ops[i] = 1;
        }
        // cout << dsu.findSet(i) << endl;
        adj[dsu.findSet(i)].push_back(i);
    }
    ll cnt = 0;
    // cout << "ops: ";
    // printv(ops);
    for(i=0;i<m;i++){
        if(adj[i].empty()) continue;
        // cout << i << ": ";
        bool valid = false;
        for(auto ele : adj[i]){
            // cout << ele << " ";
            if(ops[ele] == 1){
                valid = true;
            }
        }
        // cout << endl;
        
        if(valid){
            for(auto ele : adj[i]){
                if(vx[ele] != vy[ele]){
                    cnt++;
                }
            }
        }else{
            if((ll)adj[i].size() == 1){
                ll node = adj[i][0];
                if(vx[node] != vy[node]) cnt++;
            }else
                cnt += (ll)adj[i].size() + 1;
        }
        // cout << endl;
    }

    cout << cnt << endl;

    
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