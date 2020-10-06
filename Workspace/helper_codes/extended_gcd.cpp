#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
#define all(x) (x).begin(), (x).end()
#define MOD 998244353
#define PI acos(-1)

/**************** Description of egcd *****************
What Extended GCD function does:
Suppose gcd(a, b) = d, then it can be proved that for some integer x, y, a * x + b * y = d
Extended gcd(read egcd) returns the gcd, x, y.
Obviously, there may exist more that one possible x, y pair. The general form for x and y
is x_ = x + t * b, y_ = y + t * a for every integer t.
Usage: Check whether there's a integer solution for x, y in the equation a * x + b * y = c.
Check whether egcd(a, b) divides c or not, if yes, then x, y exists, otherwise not.

Sample problem: https://codeforces.com/contest/932/problem/C
 **/


vll egcd(ll a, ll b){
    assert(a >= b);
    assert(b >= 0) ;
    assert(a + b > 0);
    ll d, x, y;
    if(b == 0) {
        d = a;
        x = 1;
        y = 0;
    }
    else{
        vll ret = egcd(b, a % b);
        d = ret[0];
        x = ret[2];
        y = ret[1] - ret[2] * (a / b);
    }
    assert(a % d == 0);
    assert(b % d == 0);
    assert(d == a * x + b * y);
    return {d, x, y};
}

int main() {
    ios::sync_with_stdio(false);
    ll tt = 1;
    vector<ll> v = egcd(6, 4);
    cout << v[0] << " " << v[1] << " " << v[2] << '\n';
    return 0;
}