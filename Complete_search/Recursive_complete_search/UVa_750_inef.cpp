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
    for(int i=0;i<8;i++){
        bool flag = true;
        for(int j=0;j<col;j++){
            if(i == column[j] or abs(j - col) == abs(column[j] - i)){
                // cout << i << " " << j << "\n";
                flag = false;
            }
        }
        if(flag){
            column[col] = i;
            backtrack(a, b, col+1);
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