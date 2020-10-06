#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 100000000000000000
#define all(x) (x).begin(), (x).end()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))

void printv(vector<int> & v) {for(auto ele : v) cout << ele+1 << " "; cout << "\n";}

vector<vector<int>> cost(8, vector<int>(8));
vector<int> column(8);
bitset<30> row, ld, rd;
int sum, mx;

void backtrack(int col){
    // cout << col << "\n";
    if(col == 8){
        // cout << col << "\n";
        // cout << right << setw(2) << cnt++ << "      ";
        mx = max(sum, mx);
        return;
    }
    for(int r=0;r<8;r++){
        if(!row[r] and !rd[r + col] and !ld[r - col + 8 - 1]){
            row[r] = rd[r + col] = ld[r - col + 8 - 1] = true;
            column[col] = r; 
            int prevSum = sum;
            sum += cost[r][col];
            backtrack(col+1);
            row[r] = rd[r + col] = ld[r - col + 8 - 1] = false;
            sum = prevSum;
        } 
    }
}

void solve(){
    int n, m, i, j, k, l;
    sum = 0;
    mx = 0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            cin >> cost[i][j];
        }
    }
    backtrack(0);
    cout << right << setw(5) << mx << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // ONLINE_JUDGE
    int tt = 1; 
    cin >> tt;
    while(tt--){
        solve();
    }
}