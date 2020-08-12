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

struct myComp {
    bool operator() (string s1, string s2) {
        if(s1.size() != s2.size()){
            return s1.size() < s2.size();
        }
        return s1 < s2;
    }
};


map<string, bool, myComp> mp;
int mn;
int ans;

int tx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int ty[8] = {1, -1, 0, -1, 1, 0, -1, 1};

bool mark[20][20];
vector<string> v(20);
int n;
void backtrack(string s, int i, int j){
    if(mark[i][j] || (i < 0 || i >= n || j < 0 || j >= n) || (!s.empty() and s[s.size()-1] >= v[i][j]))      
        return;
    s.push_back(v[i][j]);
    mark[i][j] = true;
    if(s.size() >= 3){
        mp[s] = true;
    }
    
    for(int k=0;k<8;k++){
        backtrack(s, i + tx[k], j + ty[k]);
    }
    
    mark[i][j] = false;
}

void solve(){
    int i, j;
    cin >> n;
    mp.clear();
    for(i=0;i<n;i++){
        cin >> v[i];
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
             backtrack("", i, j);
        }
    }
    
    for(auto ele : mp){
        cout << ele.first << "\n";
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // ONLINE_JUDGE
    int tt = 1; 
    cin >> tt;
    int c = 1;
    while(tt--) {
        solve();
        if(tt) cout << "\n";
    }
}