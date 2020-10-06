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

#define MX 1000001

vector<ll> primes;
bitset<MX> isNotPrime;                       // Compact STL for Sieve, better than vector<bool> !!

void sieve(ll n) {                           // Generate primes upto n
    ll i, j;
    isNotPrime[1] = true;
    for (i = 4; i <= n; i += 2) {
        isNotPrime[i] = true;
    }
    primes.push_back(2);
    for (i = 3; i <= n; i += 2) {
        if (!isNotPrime[i]) {
            primes.push_back(i);
            if (i * i <= n) {
                for (j = i * i; j <= n; j += i + i) {         // From j = i * i. Because i * 2, i * 3, ... are already
                                                              // crossed out by 2, 3 respectively
                    isNotPrime[j] = true;
                }
            }
        }
    }
}

bool isPrime(ll x) {
    int i;
    if (x < MX) return !isNotPrime[x];
    for (i = 0; i < (int) primes.size(); i++) {
        if (x % primes[i] == 0) return false;
    }
    return true;
}

vll primeFactors(ll x){
    vll factors;
    ll pf_idx = 0, pf = primes[pf_idx];
    while(pf * pf <= x){
        while(x % pf == 0){
            x /= pf;
            factors.push_back(pf);
        }
        pf = primes[++pf_idx];
    }
    if(x != 1){
        factors.push_back(x);
    }
    return factors;
}

ll numberOfDivisors(ll x){
    ll pf_idx = 0, pf = primes[pf_idx], ans = 1;
    while(pf * pf <= x){
        ll power = 0;
        while(x % pf == 0){
            x /= pf;
            power++;
        }
        ans *= (power + 1);
        pf = primes[++pf_idx];
    }
    if(x != 1){
        ans *= 2;
    }
    return ans;
}

ll sumOfDivisors(ll x){
    ll pf_idx = 0, pf = primes[pf_idx], ans = 1;
    while(pf * pf <= x){
        ll p = 0;
        while(x % pf == 0){
            x /= pf;
            p++;
        }
        ans *= (power(pf, p + 1) - 1) / (pf - 1);
        pf = primes[++pf_idx];
    }
    if(x != 1){
        ans *= (power(x, 2) - 1) / (x - 1);
    }
    return ans;
}

ll phi(ll x){               // Euler's totient function
    ll pf_idx = 0, pf = primes[pf_idx], ans = x;
    while(pf * pf <= x){
        if(x % pf == 0) ans -= ans / pf;
        while(x % pf == 0){
            x /= pf;
        }
        pf = primes[++pf_idx];
    }
    if(x != 1){
        ans -= ans / x;
    }
    return ans;
}

void solve(ll c){
    ll n, m, i, j, k, x = 0, l, r;
    cout << phi(36) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // ONLINE_JUDGE
    sieve(1000000);
    ll tt = 1;
    // cin >> tt;
    ll cs = 1;
    while (tt--)
        solve(cs++);
    return 0;
}