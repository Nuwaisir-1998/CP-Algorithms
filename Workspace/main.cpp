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

void solve(){
    ll n, m, i, j, x, y;
    string s;
    cin >> s;
    cin >> x >> y;
    n = (ll)s.size();
    vt<ll> ones(n, 0);
    vt<ll> zeros(n, 0);
    vt<ll> pos;
    for(i=0;i<n;i++) {
        if(s[i]=='?') pos.push_back(i);
    }

    vt<vt<ll>> cnts;
    
    ll val, zo, oz;
    if(x < y){
        val = 0;
        zo = x;
        oz = y;
    }else {
        val = 1;
        zo = y;
        oz = x;
    }
    ll op = 1 - val;

    for(i=0;i<(ll)pos.size();i++) {
        s[pos[i]] = op + 48;
    }
    // printv(cnts[val]);
    // printv(cnts[op]);
    // cout << s << endl;
    for(i=0;i<n;i++){
        if(i == 0){
            if(s[i] == '1') {
                ones[i] = 1;
            }
            else if(s[i] == '0') zeros[i] = 1;
        }
        else if(s[i] == '1'){
            ones[i] = 1 + ones[i-1];
            zeros[i] = zeros[i-1];
        }else if(s[i] == '0') {
            zeros[i] = 1 + zeros[i-1];
            ones[i] = ones[i-1];
        }
        else {
            ones[i] = ones[i-1];
            zeros[i] = zeros[i-1];
        }
    }
    cnts.push_back(zeros);
    cnts.push_back(ones);

    ll sum = 0;
    // cout << zo << " " << oz << " " << val << " " << op << endl;
    for(i=1;i<n;i++){
        if(s[i] == val + 48) sum += cnts[op][i-1] * oz;
        else sum += cnts[val][i-1] * zo;
        // cout << "s " << sum << endl;
    }
    // cout << sum << endl;
    ll mn = sum;
    for(i=0;i<(ll)pos.size();i++){
        // cout << "s : " << endl;
        ll left = (pos[i] == 0) ? 0 : cnts[val][pos[i] - 1] + i;
        // cout << left << " - " <<  (cnts[val][n-1] - cnts[val][pos[i]]) << endl;
        sum -= (left * zo + (cnts[val][n-1] - cnts[val][pos[i]]) * oz);
        // cout << sum << " " << endl;
        left = (pos[i] == 0) ? 0 : cnts[op][pos[i] - 1] - i;
        // cout << left << " - " <<  (cnts[op][n-1] - cnts[op][pos[i]]) << endl;
        sum += (left * oz + (cnts[op][n-1] - cnts[op][pos[i]]) * zo);
        // cout << sum << endl;
        mn = min(mn, sum);
    }

    cout << mn << endl;
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
    return 0;
}