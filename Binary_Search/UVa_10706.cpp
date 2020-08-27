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

ll numOfDigits(ll x){
    ll cnt = 0;
    while(x){
        cnt++;
        x /= 10;
    }
    return cnt;
}

vector<ll> sz;
vector<ll> cum;
vector<ll> sz2;

void solve(ll c){
    ll n, m, i, j, d, k, l;
    cin >> n;
    // for(i=0;i<15;i++){
    //     cout << sz[i] << " ";
    // }
    // cout << "\n";
    ll idx = lower_bound(cum.begin(), cum.end(), n) - cum.begin();
    
    ll target = n - cum[idx-1];
    ll idx2 = lower_bound(sz.begin(), sz.end(), target) - sz.begin();
    // cout << idx << " " << idx2 << " " << target << "\n";

    ll div10 = sz[idx2] - target + 1;
    // cout << div10 << "\n";
    ll val = idx2, rem = idx2;
    while(div10){
        rem = val % 10;    
        val /= 10;
        div10 --;
    }
    cout << rem << "\n";
        

}

int main()
{
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // ONLINE_JUDGE
    sz.push_back(0);
    sz2.push_back(0);
    cum.push_back(0);
    for(ll i=1;i<=100000;i++){
        sz.push_back(sz[i-1] + numOfDigits(i));
        cum.push_back(cum[i-1] + sz[i]);
        sz2.push_back(numOfDigits(i));
    }
    ll tt = 1;
    cin >> tt;
    ll cs = 1;
    while (tt--)
        solve(cs++);
    // cout << numOfDigits(1);
    return 0;
}