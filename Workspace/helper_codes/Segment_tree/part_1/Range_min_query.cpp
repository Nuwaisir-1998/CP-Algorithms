/*********************************************************************************************/
//                            SEGMENT TREE FOR RANGE MINIMUM QUERY
//                  mins(l, r) => returns the minimum value of [l, r] (inclusive)
//                  set(i, val) => sets the value of the ith index to val
//
/*********************************************************************************************/


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

struct segTree {
/**      (l, r) is the main segment      **/
/**      sum(l, r) => sum of [l, r), notice that, r is not included in the segment **/
    ll size;
    vector<ll> mins;

    segTree(ll n){
        init(n);
    }

    void init(ll n){
        size = 1;
        while(size < n) size *= 2;
        mins.assign(2 * size, 0LL);
    }

    void build(vector<ll> & a, ll x, ll lx, ll rx){
        if(rx == lx){
            if(lx < (ll)a.size()){ // checking this as we added some extra 0s to the main array
                mins[x] = a[lx];
            }
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m+1, rx);
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);    /** changable **/
    }

    void build(vector<ll> & a){
        build(a, 0, 0, size-1);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx){
        if(rx == lx) {
            mins[x] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if(i <= m){
            set(i, v, 2 * x + 1, lx,  m);
        }else{
            set(i, v, 2 * x + 2, m+1,  rx);
        }
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);    /** changable **/
    }

    void set(ll i, ll v){
        set(i, v, 0, 0, size-1);
    }

    ll rmq(ll l, ll r, ll x, ll lx, ll rx){
        if(lx > r or l > rx) return INF;                /** changable **/
        if(lx >= l and rx <= r) return mins[x];
        ll m = (lx + rx) / 2;
        ll s1 = rmq(l, r, 2 * x + 1, lx, m);
        ll s2 = rmq(l, r, 2 * x + 2, m+1, rx);
        return min(s1, s2);                                 /** changable **/
    }

    ll rmq(ll l, ll r){
        return rmq(l, r, 0, 0, size-1);
    }
};

void solve(ll cs){
    ll n, k, i, j, l, m;
    cin >> n >> m;
    segTree st(n);
    vector<ll> a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    st.build(a);
    while(m--){
        ll op;
        cin >> op;
        if(op == 1){
            ll i, v;
            cin >> i >> v;
            st.set(i, v);
        }else{
            ll l, r;
            cin >> l >> r;
            cout << st.rmq(l, r-1) << endl;
        }
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