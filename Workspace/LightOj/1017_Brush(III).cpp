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
#define PI acos(-1)
#define MAXN 200005
#define INF 1000000000000000000
#define nl '\n'
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
 
template <typename T>
void printv(vector<T> &v){for (auto e : v) cout << e << ' ';cout << '\n';}
 
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
ll n, w;
vector<ll> y;
vector<vector<ll>> dp(103, vector<ll> (103, 0));

ll backtrack(ll left, ll steps){
    if(steps == 0 or left >= n) return 0;
    ll mx = 0;
    if(dp[left][steps]) return dp[left][steps];
    // cout << y[left] << " " << y[right] << " " << steps << " " << mx << "\n";
    
    ll idx = upper_bound(y.begin(), y.end(), y[left] + w) - y.begin();
    ll count = idx - left;
    ll val1 = backtrack(left+1, steps);
    ll val2 = backtrack(idx, steps-1);
    mx = max(val1, val2 + count);
    
    // cout << y[left] << " " << y[right] << " " << steps << " " << mx << "\n";
    dp[left][steps] = mx;
    return mx;
}

void solve(ll cs){
    ll m, i, j, k, a, b;
    cin >> n >> w >> k;
    y.clear();
    for(i=0;i<=n;i++){
        for(j=0;j<=k;j++){
            dp[i][j] = 0;
        }
    }
    for(i=0;i<n;i++){
        cin >> a >> b;
        y.push_back(b);
    }
    sort(y.begin(), y.end());
    
    cout << "Case " << cs << ": " << backtrack(0, k) << '\n';


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