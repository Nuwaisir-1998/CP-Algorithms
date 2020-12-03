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
#define MOD9 998244353
#define PI acos(-1)
#define MAXN 200005
#define INF 100000000000000000
#define nl '\n'
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define ff first
#define ss second
#define vt vector
#define FOR(n) for(i=0;i<n;i++)
 
template <typename T>
void printv(vector<T> &v){for (auto e : v) cout << e << ' ';cout << '\n';}
template <typename T>
void printst(set<T> &v){for (auto e : v) cout << e << ' ';cout << '\n';}
template <typename T>
void dbg(T x) {cerr << "x is " << x << '\n';}

struct custom_hash {
    // to make unordered map safe
    static uint64_t splitmix64(uint64_t x) {
        // http://xor_shift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
unordered_map<ll, ll, custom_hash> safe_map;
gp_hash_table<ll, ll, custom_hash> safe_hash_table;

/********************************************************************/

struct sparse_table{
    ll row, col;
    vt<ll> v;
    vt<vt<ll>> table;
    sparse_table(vector<ll> v){
        setV(v);
    }
    void setV(vt<ll> & v){
        this -> v = v;
        this -> row = v.size();
        this -> col = log2(v.size()) + 1;
        table.resize(row);
        for(ll i=0;i<row;i++) table[i].resize(col);
    }
    void build_for_rmq(){
        for(ll i=0;i<row;i++){
            table[i][0] = v[i];
        }
        for(ll i=1;i<col;i++){
            for(ll j=0; j+(1<<(i-1))<row;j++){
                table[j][i] = min(table[j][i-1], table[j + (1 << (i - 1))][i-1]);
            }
        }
    }
    ll rmq(ll l, ll r){             // inclusive
        ll lg = log2(r - l + 1);
        ll minimum = min(table[l][lg], table[r - (1 << lg) + 1][lg]);
        return minimum;
    }
};


bool found;

void shift(multiset<int> &l, multiset<int> &r, int val) {
	l.erase(l.find(val));
	r.insert(val);
}

void check(const multiset<int> &lf, const multiset<int> &mid, const multiset<int> &rg) {
	if (found || lf.empty() || mid.empty() || rg.empty()) {
		return;
	}
	if (*lf.rbegin() == *mid.begin() && *mid.begin() == *rg.rbegin()) {
		found = true;
		cout << "YES" << endl;
		cout << lf.size() << " " << mid.size() << " " << rg.size() << endl;
	}
}

void solve2(ll cs, vector<ll> a){
    int n;
		// cin >> n;
		// vector<int> a(n);
        n = a.size();
		// for (auto &it : a) cin >> it;
		
		found = false;
		multiset<int> lf, mid(a.begin(), a.end()), rg;
		int r = n - 1;
		for (int l = 0; l < n - 2; ++l) {
			shift(mid, lf, a[l]);
			while (r - 1 >= l && a[r] <= *lf.rbegin()) {
				shift(mid, rg, a[r]);
				--r;
			}
			
			while (r - 1 < l) {
				shift(rg, mid, a[r + 1]);
				++r;
			}
			
			check(lf, mid, rg);
			
			shift(lf, mid, a[l]);
			check(lf, mid, rg);
			shift(mid, lf, a[l]);
			
			if (rg.empty()) continue;
			
			shift(rg, mid, a[r + 1]);
			check(lf, mid, rg);
			shift(mid, rg, a[r + 1]);
		}
		if (!found) {
			cout << "NO" << endl;
		}
}

bool solve(ll cs, vt<ll> v){
    ll n, m, i, j, k;
    // cin >> n;
    // vt<ll> v(n);
    // for(i=0;i<n;i++){
    //     cin >> v[i];
    // }
    n = v.size();
    sparse_table spt(v);
    spt.build_for_rmq();
    vt<ll> mx_begin(n, 0);
    vt<ll> mx_end(n, 0);
    mx_begin[0] = v[0];
    mx_end[n-1] = v[n-1];
    for(i=1;i<n;i++) mx_begin[i] = max(mx_begin[i-1], v[i]);
    for(i=n-2;i>=0;i--) mx_end[i] = max(mx_end[i+1], v[i]);
    reverse(all(mx_end));
    // printv(mx_end);
    for(i=0;i<n;i++){
        // mx_end(0 -> n-i)
        ll val = mx_begin[i];
        ll idx = upper_bound(mx_end.begin(), mx_end.begin() + n - (i + 2), val) - mx_end.begin();

        // cout << i << " " << val << " " << idx  << endl;

        if(idx == 0) continue;
        if(mx_end[idx - 1] != val) continue;
        if(n - idx - 1 - (i + 1) + 1 <= 0) continue;
        // min of [i + 1, n - idx] must be val
        if(spt.rmq(i+1, n-idx-1) == val){
            cout << "YES\n";
            cout << i+1 << " " << n - idx - 1 - (i + 1) + 1 << " " << idx << endl;
            return true;
        }else{
            ll right = n - idx;
            if(right + 1 < n and v[right] == val and v[right + 1] == val){
                // right++;
                if(spt.rmq(i+1, right) == val){
                    cout << "YES\n";
                    cout << i + 1 << " " << right - (i + 1) + 1 << " " << n - right - 1 << endl;
                    return true;
                }
            }
        }
    }

    cout << "NO\n";
    return false;
    // printv(mx_begin);
    // printv(mx_end);
    
    
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
    srand(time(0));
    // while (tt--){
    //     ll n = rand() % 15 + 1;
    //     vt<ll> rand_v(n);
    //     for(ll i=0;i<n;i++){
    //         rand_v[i] = rand() % 10 + 1;
    //     }
    //     bool my = solve(cs++, rand_v);
    //     solve2(cs++, rand_v);
    //     if(found and !my){
    //         cout << "Found bug\n";
    //         cout << n << endl;
    //         printv(rand_v);
    //         return 0;
    //     }
    // }
    return 0;
}