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

ll MX;

ll BS(ll root, ll balls){
    if(root * 2 + 1 < MX){
        if(balls % 2) return BS(root * 2, (balls + 1) / 2);
        else return BS(root * 2 + 1, balls / 2);
    }else return root;
}

void solve(ll c){
    ll n, m, i, j, d, k, l;
    while(cin >> n >> m){
        if(n == 1 and m == 1) return;
        string ans;
        ll atNum = 1, atDen = 1;
        ll lNum = 1, lDen = 0, rNum = 0, rDen = 1;
        while(atDen != n or atNum != m){
            if(n * atNum < m * atDen){
                rNum = atNum;
                rDen = atDen;
                atDen += lDen;
                atNum += lNum;
                ans.push_back('L');
            }else{
                lNum = atNum;
                lDen = atDen;
                atDen += rDen;
                atNum += rNum;
                ans.push_back('R');
            }
            // cout << atDen << "/" << atNum << "\n";
        }
        cout << ans << '\n';
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