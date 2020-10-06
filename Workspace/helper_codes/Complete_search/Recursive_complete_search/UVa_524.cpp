#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define MOD 1000000007
#define INF 100000000000000000
#define all(x) (x).begin(), (x).end()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))

void printv(vector<int> & v) {for(auto ele : v) cout << ele << " "; cout << "\n";}

int n;
vector<int> v(16);
bool isPrime[35];
bool used[17];   

void backtrack(int idx, int val){

    v[idx] = val;
    // cout << idx << " " << val << '\n';
    used[val] = true;

    if(idx == n-1){
        if(isPrime[v[idx] + v[0]]){
            for(int i=0;i<v.size();i++){
                cout << v[i];
                if(i < v.size() - 1) cout << " ";
                else cout << "\n";
            }
        }
        used[val] = false;
        return;
    }

    for(int i=2;i<=n;i++){
        if(!used[i]) {
            if(isPrime[v[idx] + i])
                backtrack(idx + 1, i);
        }
    }

    used[val] = false;
}

bool solve(int c){
    int i, j;
    if(!(cin >> n)) return false;
    // cout << n << "\n";
    v.resize(n);
    if(c != 1) cout << "\n";
    cout << "Case " << c << ":\n";
    backtrack(0, 1);
    return true;

    
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // ONLINE_JUDGE
    int tt = 1; 
    // cin >> tt;
    int c = 1;

    vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};
    for(auto ele : primes){
        isPrime[ele] = true;
    }

    while(solve(c++)) {
        
        // if(tt) cout << "\n";
    }
}