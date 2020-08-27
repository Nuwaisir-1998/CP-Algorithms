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

/*************    check all diagonals of the square. ***************/

void solve(ll c){
    ll n, m, i, j, d = 0, k, l, r;
    while(true){
        d++;
        cin >> n >> m;
        if(n == 0 and m == 0) return;
        vector<vector<ll>> v(n, vector<ll> (m));
        vector<vector<ll>> diag(max(m,n)*2 + 2);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> v[i][j];
                // cout << j - i + n - 1 << "\n"; 
                diag[j - i + n - 1].push_back(v[i][j]);
            }
        }
        // for(i=0;i<diag.size();i++){
        //     printv(diag[i]);
        // }
        ll q;
        cin >> q;
        while(q--){
            cin >> l >> r;
            ll ans = 0, mx = 0;
            for(i=0;i<diag.size();i++){
                ll i1 = lower_bound(diag[i].begin(), diag[i].end(), l) - diag[i].begin();
                ll i2 = upper_bound(diag[i].begin(), diag[i].end(), r) - diag[i].begin();
                mx = max(mx, i2 - i1);
            }

            cout << mx << "\n";
        }
        cout << "-\n";
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