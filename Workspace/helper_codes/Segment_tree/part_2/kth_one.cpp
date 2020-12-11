/*********************************************************************************************/
//                               SEGMENT TREE FOR NUMBER OF MINIMUMS IN A RANGE QUERY
//                  rmq(l, r) => returns the (minimum value, frequency of the min value in [l, r] (inclusive)) pair
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

// Problem link: https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B

/********************************************************************/

// sum -> just the sum
struct item {
    ll sum;
};

struct segTree {
/**      (l, r) is the main segment      **/
/**      sum(l, r) => sum of the values of the range [l, r] **/
    ll size;

    vector<item> values;

    segTree(ll n){
        init(n);
    }

    item NEUTRAL_ELEMENT = {0};

    item merge(item a, item b){
        return {
            a.sum + b.sum
        };
    }

    item single(ll v){
        return {v};
    }

    void init(ll n){
        size = 1;
        while(size < n) size *= 2;
        values.resize(2 * size);
    }

    void build(vector<ll> & a, ll x, ll lx, ll rx){
        if(rx == lx){
            if(lx < (ll)a.size()){ // checking this as we added some extra 0s to the main array
                values[x] = single(a[lx]);
            }
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m+1, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);    /** changable **/
    }

    void build(vector<ll> & a){
        build(a, 0, 0, size-1);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx){
        if(rx == lx) {
            values[x] = single(v);
            return;
        }
        ll m = (lx + rx) / 2;
        if(i <= m){
            set(i, v, 2 * x + 1, lx,  m);
        }else{
            set(i, v, 2 * x + 2, m+1,  rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);    /** changable **/
    }

    void set(ll i, ll v){
        set(i, v, 0, 0, size-1);
    }

    item calc(ll l, ll r, ll x, ll lx, ll rx){
        if(lx > r or l > rx) return NEUTRAL_ELEMENT;                /** changable **/
        if(lx >= l and rx <= r) return values[x];
        ll m = (lx + rx) / 2;
        item s1 = calc(l, r, 2 * x + 1, lx, m);
        item s2 = calc(l, r, 2 * x + 2, m+1, rx);
        return merge(s1, s2);                                 /** changable **/
    }

    item calc(ll l, ll r){
        return calc(l, r, 0, 0, size-1);
    }

    ll find(ll k, ll x, ll lx, ll rx){      // finding the index of kth one
        if(lx == rx) return lx;
        ll sum_left = values[x * 2 + 1].sum;
        ll mid = (lx + rx) / 2;
        if(sum_left > k){
            return find(k, 2 * x + 1, lx, mid);
        }else{
            return find(k - sum_left, 2 * x + 2, mid + 1, rx);
        }
    }

    ll find(ll k){
        return find(k, 0, 0, size-1);
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
    // cout << "0 -> 3" << endl;
    // cout << st.calc(1, 3).sum << endl;
    while(m--){
        ll op;
        cin >> op;
        if(op == 1){
            ll idx;
            cin >> idx;
            a[idx] = 1 - a[idx];
            st.set(idx, a[idx]);
        }else{
            cin >> k;
            cout << st.find(k) << endl;
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