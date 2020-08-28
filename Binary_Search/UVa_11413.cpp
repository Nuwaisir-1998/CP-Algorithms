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

bool check(vector<ll> & v, ll mx, ll sz){
    ll cnt = 1, filled = 0;
    for(int i=0;i<v.size();i++){
        if(v[i] > mx){
            return false;
        }else if(filled + v[i] <= mx){
            filled += v[i]; 
        }else{
            cnt++;
            filled = v[i];
        }
    }
    return (cnt <= sz);
}

void solve(ll c){
    ll n, i, j, k, l, m;

    while(cin >> n >> k){
        vector<ll> v(n);
        ll sum = 0;
        for(i=0;i<n;i++){
            cin >> v[i];
            sum += v[i];
        }

        ll left = 1, right = sum, mid;
        ll ans;
        while(left <= right){
            mid = (left + right) / 2;
            bool f = check(v, mid, k);
            if(f){
                right = mid-1;
                ans = mid;
            }else{
                left = mid+1;
            }
        }
        cout << ans << nl;
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