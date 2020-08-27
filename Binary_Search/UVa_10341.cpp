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
    double p, q, r, s, t, u, x, l = 0, r_ = 1;
    double e = 2.718281828, eps = 1e-9, expr;
    while(cin >> p >> q >> r >> s >> t >> u){
        ll cnt = 1000;
        l = 0, r_ = 1;
        while(cnt--){
            x = (l + r_) / 2;
            // cout << x << "\n";
            expr = p*pow(e,-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
            if(expr > 0){
                l = x;
            }else r_ = x;
            if(abs(expr - 0) < eps) {
                break;
            }
        }
        // cout << expr << "\n";   
        if(abs(expr) < eps){
            cout << fixed << setprecision(4) << x << "\n";
        }else cout << "No solution\n";
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
    // cout << numOfDigits(1);
    // cout << 1 << "\n";
    return 0;
}