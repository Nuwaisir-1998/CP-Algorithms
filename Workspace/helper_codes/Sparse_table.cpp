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

struct sparse_table{
    ll row, col;
    vt<ll> v;
    vt<vt<ll>> table;
    sparse_table(vector<ll> v){
        setV(v);
    }
    void setV(vt<ll> & v){
        this -> v = v;
        this -> row = v.size();
        this -> col = log2(v.size()) + 1;
        table.resize(row);
        for(ll i=0;i<row;i++) table[i].resize(col);
    }
    void build_for_rmq(){
        for(ll i=0;i<row;i++){
            table[i][0] = v[i];
        }
        for(ll i=1;i<col;i++){
            for(ll j=0; j+(1<<(i-1))<row;j++){
                table[j][i] = min(table[j][i-1], table[j + (1 << (i - 1))][i-1]);
            }
        }
    }
    ll rmq(ll l, ll r){             // inclusive
        ll lg = log2(r - l + 1);
        ll minimum = min(table[l][lg], table[r - (1 << lg) + 1][lg]);
        return minimum;
    }
};

void solve(ll cs){
    ll n, i, j;
    cin >> n;
    vt<ll> v(n);
    FOR(n) cin >> v[i];
    sparse_table spt(v);
    spt.build_for_rmq();
    cout << spt.rmq(0,n-1) << endl;
    
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
    ll cs = 1;
    while (tt--)
        solve(cs++);
    
    return 0;
}