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

/**************** Description of Chinese Remainder Theorem (crt) *****************
    For every remainder ra mod a, and rb mod b, if gcd(a, b) == 1, then there exists
    an integer n such that n % a == ra and n % b == rb. And if n1, and n2 are two such
    integers, then n1 is congruent to n2 modulo a*b, meaning ab divides (n1 - n2).

    Consider this problem:
        You are given two relations
        (1) x % 17 = 7
        (2) x % 11 = 3
        Find the minimum value of x.

    solve:
        The following crt function will output the answer.
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

ll crt(ll n1, ll r1, ll n2, ll r2) {
    if(n1 < n2) {
        swap(n1, n2);
        swap(r1, r2);
    }
    vll ret = egcd(n1, n2);
    ll x = ret[1];
    ll y = ret[2];
    ll ans = (n1 * x * r2 + n2 * y * r1) % (n1 * n2);
    if(ans < 0) ans += n1 * n2;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    ll tt = 1;
    cout << crt(17, 7, 11, 3) << '\n';
    return 0;
}
