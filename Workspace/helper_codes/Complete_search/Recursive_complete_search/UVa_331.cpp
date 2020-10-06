#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define MOD 1000000007
#define INF 100000000000000000
#define all(x) (x).begin(), (x).end()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))

void printv(vector<int> & v) {for(auto ele : v) cout << ele+1 << " "; cout << "\n";}

// unordered_map<int,int> um;
int mn;
int ans;

void backtrack(vi & v, int cnt){
    bool f = false;
    // cout << cnt << "\n";
    for(int i=0;i<v.size()-1;i++){
        if(v[i] > v[i+1]){
            f = true;
            swap(v[i], v[i+1]);
            backtrack(v, cnt+1);
            swap(v[i], v[i+1]);
        }
    }
    if(!f) {
        if(cnt < mn){
            mn = cnt;
            ans = 0;
            if(cnt != 0)
                ans = 1;
        }else if(cnt == mn){
            if(cnt != 0) ans++;
        }
    }
}

bool solve(int c){
    int i, n;
    cin >> n;
    if(n == 0) return false;
    mn = INT_MAX;
    ans = 0;
    // um.clear();
    vector<int> v(n);
    for(i=0;i<n;i++){
        cin >> v[i];
    }

    backtrack(v, 0);
    cout << "There are " << ans << " swap maps for input data set " << c << ".\n";
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
    while(solve(c++)){
        
    }
}