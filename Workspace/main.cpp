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
void printv(vector<T> &v){for (auto e : v) cout << e << ' ';cout << '\n';}
template <typename T>
void printst(set<T> &v){for (auto e : v) cout << e << ' ';cout << '\n';}
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

struct matrix{
    vector<vector<ll>> mat;
    ll n = 0, m = 0;

    matrix(ll n, ll m, ll init_val){  // constructs an n x m matrix with all values = val
        vector<vector<ll>> v(n, vector<ll>(m, init_val));
        init(v);
    }

    matrix(vector<vector<ll>> mat){
        init(mat);
    }

    void init(vector<vector<ll>> v){
        this -> mat = v;
        n = mat.size();
        if(n) m = mat[0].size();
    }
    
    void print(){
        // cout << n << " " << m << endl;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

matrix identity_matrix(ll n){
    vector<vector<ll>> v(n, vector<ll> (n));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            v[i][j] = 0;
            if(i == j) v[i][j] = 1;
        }
    }
    matrix mat(v);
    return mat;
}

matrix mat_mul(matrix a, matrix b, ll mod){
    assert(a.m == b.n);
    matrix res(a.n, b.m, 0);
    for(ll i=0;i<res.n;i++){
        for(ll j=0;j<res.m;j++){
            ll sum = 0;
            for(ll k=0;k<a.m;k++){
                sum = (sum + ((a.mat[i][k] % mod) * (b.mat[k][j] % mod)) % mod) % mod;
            }
            res.mat[i][j] = sum;
        }
    }
    return res;
}    

matrix matrix_expo ( matrix a, ll p, ll m )
{
    matrix res = identity_matrix(a.n);
    matrix x = a;
    while (p)
    {
        if (p & 1) //p is odd
        {
            res = mat_mul(res, x, m);
        }
        x = mat_mul(x, x, m);
        p = p >> 1;
    }
    return res;
}

void solve(ll cs){
    ll m, n, k, tt, i, j, l;

    // cin >> tt;
    while(cin >> n >> m){
        ll mod = 1;
        for(i=0;i<m;i++){
            mod *= 2;
        }

        matrix mat(2, 2, 1);
        mat.mat[1][1] = 0;

        if (n < 2) {
            if (n == 0) cout << 0 << endl;
            if (n == 1) cout << 1 % mod << endl;
        } else {
            mat = matrix_expo(mat, n-1, mod);
            cout << mat.mat[0][0] << endl;
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