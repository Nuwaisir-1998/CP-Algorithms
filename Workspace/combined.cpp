#include <bits/stdc++.h>
using namespace std;/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;*/

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf (1<<30)
#define infll (1LL<<62)
#define abs(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define fbo(k) find_by_order(k) ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef set <int> si;
typedef multiset <int> msi;
typedef multiset <int>::iterator mit;
typedef map <int, int> mii;
typedef map <int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e6 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

int primes[mx / 10];
bool is_comp[mx];

int sieve()
{
    primes[0] = 2;
    int prime_count = 1;
    for (int i = 4; i < mx; i += 2) is_comp[i] = true;
    for (int i = 3; i < mx; i += 2) {
        if (is_comp[i]) continue;
        primes[prime_count++] = i;
        for (ll j = (ll) i * i; j < mx; j += i) {
            is_comp[j] = true;
        }
    }
    return prime_count;
}

int main()
{
    int prime_count = sieve();

    int test = 1;
    scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        ll a, b, m, ans;
        scanf("%lld %lld %lld",&a, &b, &m);
        if (a == b) ans = 0;
        else {
            if (a < b) swap(a, b);
            ll d = a - b;
            vector <ll> div_list;
            for (int i = 0; i < prime_count; i++) {
                if (d % primes[i] == 0) {
                    div_list.pb(primes[i]);
                    while (d % primes[i] == 0) d /= primes[i];
                }
                if (d == 1) break;
            }
            if (d != 1) {
                div_list.pb(d);
                assert(d >= mx);
            }

            int k = div_list.size();
            int mask = (1 << k);
            ans = m + 1;
            for (int i = 1; i < mask; i++) {
                int bit_count = 0;
                int current_mask = i;
                int j = 0;
                ll mult = 1;
                while (current_mask != 0) {
                    bit_count += (current_mask & 1);
                    current_mask = (current_mask >> 1);
                    mult *= div_list[j];
                    j++;
                }
                ll temp = (a + m) / mult - (a - 1) / mult;
                if (bit_count & 1) ans -= temp;
                else ans += temp;
            }
        }

        printf("Case %d: %lld\n",cas, ans);
    }

    return 0;
}