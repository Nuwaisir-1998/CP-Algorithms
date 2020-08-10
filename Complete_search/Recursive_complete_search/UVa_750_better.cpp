#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 100000000000000000
#define all(x) (x).begin(), (x).end()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))

void printv(vector<int> & v) {for(auto ele : v) cout << ele+1 << " "; cout << "\n";}

vector<int> column(8);
vector<bool> row(8);
vector<bool> rd(15);
vector<bool> ld(15);
int cnt;

void backtrack(int a, int b, int col){
    // cout << col << "\n";
    if(col == 8 and column[b] == a){
        // cout << col << "\n";
        cout << right << setw(2) << cnt++ << "      ";
        for(int i=0;i<column.size();i++){
            cout << column[i] + 1;
            if(i < column.size() - 1){
                cout << " ";
            }else cout << "\n";
        }
    }
    for(int r=0;r<8;r++){
        if(!row[r] and !rd[r + col] and !ld[r - col + 8 - 1]){
            row[r] = rd[r + col] = ld[r - col + 8 - 1] = true;
            column[col] = r; 
            backtrack(a, b, col+1);
            row[r] = rd[r + col] = ld[r - col + 8 - 1] = false;
        } 
    }
}

void solve(){
    int n, m, i, j, k, l;
    int a, b;
    cnt = 1;
    cin >> a >> b;
    a--; b--;
    cout << "SOLN       COLUMN\n";
    cout << " #      1 2 3 4 5 6 7 8\n\n";
    backtrack(a, b, 0);
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
        if(tt > 0) cout << "\n";
    }
    // cout << to_dec("100");
}