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

void count_sort(vector<ll> &p, vector<ll> &c){
    ll n = p.size();
    vector<ll> cnt(n);
    for(auto x : c) cnt[x]++;
    vector<ll> p_new(n);
    vector<ll> pos(n);
    pos[0] = 0;
    for(ll i=1;i<n;i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(auto x : p){
        ll i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}


void build_suffix_array(string s){
    s += "$";
    ll n = s.size();
    vector<ll> p(n), c(n);
    {
        // k = 0
        vector<pair<char, ll>> a(n);
        for(ll i=0;i<n;i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());

        for(ll i=0;i<n;i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(ll i=1;i<n;i++){
            if(a[i].first == a[i - 1].first){
                c[p[i]] = c[p[i-1]];
            }else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }

    ll k = 0;
    while((1 << k) < n){
        for(ll i=0;i<n;i++){
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        count_sort(p, c);

        vector<ll> c_new(n);
        c_new[p[0]] = 0;
        for(ll i=1;i<n;i++){
            pll prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
            pll now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if(now == prev){
                c_new[p[i]] = c_new[p[i-1]];
            }else{
                c_new[p[i]] = c_new[p[i-1]] + 1;
            }
        }
        c = c_new;
        k++;
    }

    for(ll i=0;i<n;i++){
        cout << p[i] << " " << s.substr(p[i], n-p[i]) << endl;
    }
}

void solve(ll cs){
    ll n, k, i, j, l, m;
    string s;
    cin >> s;
    build_suffix_array(s);
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