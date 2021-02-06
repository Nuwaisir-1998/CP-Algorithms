#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/numeric>
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define ordered_set tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update>
 
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define MOD9 998244353
#define PI acos(-1)
#define MAXN 500005
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

#define MXS 500005

/********************************************************************/

ll lcp(string s1, string s2){
    ll i = 0;
    while(s1[i] and s2[i] and s1[i] == s2[i]) i++;
    return i;
}

void solve(ll cs){
    ll i, j, n, m, k, x;
    cin >> n;
    vt<string> v(n);
    vt<ll> lcps(n-1);
    ll mx_len = 0;
    for(i=0;i<n;i++){
        char str[100];
        cin >> v[i];
        mx_len = max((ll)v[i].size(), mx_len);
    }
    sort(all(v));
    ll lcps_len = n - 1;
    vt<ll> last_occurs(60, -1);
    vt<ll> mx_last_occurs(60, -1);
    vt<ll> effect(60, -1);
    vt<ll> mx_effect(60, -1);
    for(i=0;i<lcps_len;i++){
        lcps[i] = lcp(v[i], v[i+1]);
    }

    ll ans = mx_len;
    for(i=0;i<n-1;i++){
        last_occurs[lcps[i]] = i;
        mx_last_occurs[lcps[i]] = i;
        for(j=1;j<=50;j++){
            mx_last_occurs[j] = max(mx_last_occurs[j-1], last_occurs[j]);
        }

        // calculate effective range for each value from 1...50
        for(j=1;j<=50;j++){
            if(last_occurs[j] == -1) continue;
            if(mx_last_occurs[j-1] > last_occurs[j]) effect[j] = -1;
            else effect[j] = mx_last_occurs[j-1] + 1;
        }
        for(j=1;j<=50;j++){
            if(effect[j] != -1){
                ans = max(ans, j * (i - effect[j] + 2));
            }
        }
    }

    cout << "Case " << cs << ": " << ans << endl;
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