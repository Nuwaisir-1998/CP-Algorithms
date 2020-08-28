#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/numeric>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std::chrono; 
  
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

/*****  Two pointer method for determining longest subarray sum <= k  ******/

void solve(ll c){
    ll n,i ,j, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    ll left = -1, right = 0, mx = 0;
    ll sum = 0;

    for(right=0; right<n; right++){
        sum += v[right];
        while(sum > k) {
            left++;
            sum -= v[left];
        }
        mx = max(mx, right - left);
    }
    cout << mx << '\n';
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
    // cout << numOfDigits(1);
    // cout << 1 << "\n";
    return 0;
}