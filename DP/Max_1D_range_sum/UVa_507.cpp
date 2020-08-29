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

void solve(ll c){
    ll n, i, j, k, l, m, s;
    cin >> n;
    // cout << "\n" << n << "\n";
    vector<ll> v(n);
    for(i=0;i<n-1;i++){
        cin >> v[i];
        // cout << i << ":" << v[i] << " ";
    }
    ll mx = 0, idxLeft = 0, idxRight = 0, left = 0;
    ll sum = 0;
    for(i=0;i<n-1;i++){
        // if(sum == 0) left = i;
        sum += v[i];
        if(sum < 0){
            sum = 0;
            left = i+1;
        }else{
            // mx = max(mx, sum);
            if(sum >= mx){
                if((sum == mx and i - left > idxRight - idxLeft) or sum > mx){
                    idxLeft = left;
                    idxRight = i;
                }
                mx = sum;
            }
            
        }
    }
    if(mx == 0) {
        // cout << -1 << "\n";
        cout << "Route " << c << " has no nice parts\n";
        return;
    }
    cout << "The nicest part of route " << c << " is between stops " << idxLeft + 1 << " and " << idxRight + 2 << "\n";

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