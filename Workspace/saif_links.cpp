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

ll lis(vector<ll> const& a) {
    ll n = a.size();
    // const int INF = 1e9;
    vector<ll> d(n+1, INF);
    d[0] = -INF;

    for (ll i = 0; i < n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (d[j-1] < a[i] && a[i] < d[j])
                d[j] = a[i];
        }
    }

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

void solve(ll cs){
    ll n, i, j, k, x;
    string pref = "https://google.com/search?q=";
    string s;
    string up = "<html><head><title>Saif The Bhuiyan's links</title></head><body><marquee><h1>Saif The Bhuiyan's links</h1></marquee>";
    string down = "</body></html>";
    cout << up << endl;
    string previous_word = "best";
    string later_word = "review";
    while(getline(cin, s)){
        // cout << "<a href=\"" << pref + previous_word + " " + s + " " + "review" << "\"" << "target=\"_blank\">" << previous_word + " " << s << " " <<  "review </a>" << endl;
        // cout << "<br>";
        cout << "<a href=\"" << pref + previous_word + " " + s << "\"" << "target=\"_blank\">" << previous_word + " " << s << "</a>" << endl;
        cout << "<br>";
        // cout << "<a href=\"" << pref + s + " " + later_word << "\"" << "target=\"_blank\">" << s << " review </a>" << endl;
        // cout << "<br>";
    }

    cout << down << endl;
    

}

int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.html", "w", stdout);
#endif // ONLINE_JUDGE

    ll tt = 1;
    // cin >> tt;
    ll cs = 1;
    while (tt--)
        solve(cs++);
    
    return 0;
}