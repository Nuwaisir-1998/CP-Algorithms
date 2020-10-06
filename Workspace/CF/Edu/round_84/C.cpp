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

void pr(char ch, ll n){
    for(int i=0;i<n;i++){
        cout << ch;
    }
}

void solve(){
    ll n, m, k, i, j;
    cin >> n >> m >> k;
    vector<ll> sx(k), sy(k), fx(k), fy(k);
    for(i=0;i<k;i++){
        cin >> sx[i] >> sy[i];
    }
    ll right = 0;
    ll left = 0;
    ll up = 0;
    ll down = 0;
    for(i=0;i<k;i++){
        cin >> fx[i] >> fy[i];
        // if(fx[i] > sx[i]) down = max(down, fx[i] - sx[i]);
        // else up = max(up, sx[i] - fx[i]);
        // if(fy[i] > sy[i]) right = max(right, fy[i] - sy[i]);
        // else left = max(left, sy[i] - fy[i]);
    }
    // if(up + down + left + right > 2*n*m){
    //     cout << -1 << '\n';
    //     return;
    // }
    cout << m - 1 + n - 1 + n*m  << "\n";

    pr('U', n-1);
    pr('L', m-1);
    for(i=0;i<n;i++){
        if(i % 2 == 0){
            // right
            pr('R', m-1);
            pr('D', 1);
        }else{
            pr('L', m-1);
            pr('D', 1);
        }
    }
    // pr('R', right);
    // pr('L', left);
     cout << "\n";
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
    // ll cs = 1;
    while (tt--)
        solve();
    
    return 0;
}