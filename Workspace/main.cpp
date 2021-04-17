#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/numeric>

// #include <atcoder/all>
// using namespace atcoder;

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define ordered_set tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update>
 
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define MOD9 998244353
#define PI acos(-1)
#define MAXN 500005
#define INF 100000000000000000
#define nl '\n'
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define ff first
#define ss second
#define vt vector
#define FOR(n) for(i=0;i<n;i++)

template <typename T>
void printv(vector<T> &v, ll add){for (auto e : v) cout << e + add << ' ';cout << '\n';}
template <typename T>
void printv(vector<T> &v){for (auto e : v) cout << e << ' ';cout << '\n';}
template <typename T>
void dbg(T x) {cerr << "x is " << x << '\n';}

#define MXS 600005

/********************************************************************/

void solve(ll cs){
    ll n, m, i, j, c, k, l, q, r, p;
    cin >> n;
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;

    string ans;

    vt<bool> mark1(2*n, 0);
    vt<bool> mark2(2*n, 0);
    vt<bool> mark3(2*n, 0);

    for(i=0;i<2*n;i++){
        if(s1[i] == s2[i]) {
            ans.push_back(s1[i]);
            mark1[i] = true;
            mark2[i] = true;
        }
        else if(s1[i] == s3[i]) {
            ans.push_back(s1[i]);
            mark1[i] = true;
            mark3[i] = true;
        }
        else if(s2[i] == s3[i]) {
            ans.push_back(s2[i]);
            mark3[i] = true;
            mark2[i] = true;
        }
    }

    ll baki1 = 0, baki2 = 0, baki3 = 0;

    for(i=0;i<2*n;i++){
        if(!mark1[i]) baki1++;
        if(!mark2[i]) baki2++;
        if(!mark3[i]) baki3++;
    }
    mark1.push_back(1);
    mark3.push_back(1);
    mark2.push_back(1);
    string fin;
    ll idx = 0;
    // cout << baki1 << " "<< baki2 << " " << baki3 << endl;
    // printv(mark2);
    ll sz = 2 * n;
    if(baki1 <= n and baki1 != 0){
        // cout << "one" << endl;
        string str;
        for(i=0;i<2*n;i++){
            cout << ans[i];
            if(mark1[i] == false){
                str += s1[i];
            }
            if(mark1[i] == false and mark1[i+1] == true){
                sz += str.size();
                cout << str;
                str = "";
            }
        }
    }else if(baki2 <= n and baki2 != 0){
        // cout << "two" << endl;
        string str;
        for(i=0;i<2*n;i++){
            cout << ans[i];
            if(mark2[i] == false){
                str += s2[i];
            }
            if(mark2[i] == false and mark2[i+1] == true){
                sz += str.size();
                cout << str;
                str = "";
            }
        }
    }else if(baki3 <= n and baki3 != 0){
        // cout << "three" << endl;
        string str;
        for(i=0;i<2*n;i++){
            cout << ans[i];
            if(mark3[i] == false){
                str += s3[i];
            }
            if(mark3[i] == false and mark3[i+1] == true){
                sz += str.size();
                cout << str;
                str = "";
            }
        }
    }
    while(sz < 3*n) {
        cout << 0;
        sz++;
    }
    cout << endl;



}

int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("./in", "r", stdin);
    freopen("./out", "w", stdout);
#endif // ONLINE_JUDGE

    ll tt = 1, cs = 1;
    cin >> tt;
    while (tt--)
        solve(cs++);
    return 0;
}