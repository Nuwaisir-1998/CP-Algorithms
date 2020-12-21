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


/********************************************************************/

set<ll> sums;

ll find_pivot(vt<ll> & v, ll left, ll right){
    ll mx = -INF;
    ll mn = INF;
    for(ll i=left;i<=right;i++){
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }
    return (mx + mn) / 2;
}

void check(vt<ll> & v, ll left, ll right){
    // cout << left << " " << right << endl;
    // cout << "v: ";printv(v);
    if(left == right){
        // cout << v[left] << endl;
        sums.insert(v[left]);
        return;
    }
    ll pivot = find_pivot(v, left, right);
    // cout << pivot << endl;
    bool shoman = true;
    for(ll i=left+1;i<=right;i++){
        if(v[i] != v[i-1]) shoman = false;
    }
    
    vll new_arr;
    ll sum = 0;
    for(ll i=left;i<=right;i++){
        if(v[i] <= pivot) new_arr.push_back(v[i]);
        // cout << v[i] << " ";
        sum += v[i];
    }
    // cout << endl;
    ll mid = left + (ll)new_arr.size() - 1;
    for(ll i=left;i<=right;i++){
        if(v[i] > pivot) new_arr.push_back(v[i]);
    }
    // cout << sum << endl;
    // cout << "n : ";
    // printv(new_arr);
    sums.insert(sum);
    if(shoman) return;
    // if(mid == right or left == mid) return;
    for(ll j=0,i=left;i<=right;i++,j++){
        v[i] = new_arr[j];
    }
    check(v, left, mid);
    check(v, mid+1, right);
}

vector<vector<ll>> nCr(201, vector<ll> (201, 0));

ll combination(ll n, ll r){
    if(n == r) nCr[n][r] = 1;
    else if(r == 0) nCr[n][r] = 1;
    else {
        if(nCr[n][r] != 0){
            return nCr[n][r];
        }else{
            nCr[n][r] = combination(n-1, r) + combination(n-1, r-1);
        }
    }
    return nCr[n][r];
}


vt<vt<ll>> LCS(1001, vt<ll> (1001, -1));

vt<ll> v1(1001), v2(1001);

ll compute_LCS(ll p1, ll p2){
    if(p1 == 0 or p2 == 0){
        if(v1[p1] == v2[p2]) LCS[p1][p2] = 1;
        else LCS[p1][p2] = 0;
    }
    if(LCS[p1][p2] != -1) return LCS[p1][p2];
    if(v1[p1] == v2[p2]){
        LCS[p1][p2] = compute_LCS(p1-1, p2-1) + 1;
    }else{
        LCS[p1][p2] = max(compute_LCS(p1-1, p2), compute_LCS(p1, p2-1));
    }
    return LCS[p1][p2];
    
}

void solve(){
    ll i, j, k, a, b, n, m, q;
    ll  t;
    cin >> n >> m;
    
    for(i=0;i<n;i++){
        cin >> v1[i];
    }
    for(i=0;i<m;i++){
        cin >> v2[i];
    }

    ll val = compute_LCS(n-1, m-1);
    cout << val << endl;
    cout << (n - val) + (m - val) << endl;

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
    // for(int i=0;i<1000;i++){
    //     cout << 4 << " " << 0.1 << endl;
    // }
    
    return 0;
}