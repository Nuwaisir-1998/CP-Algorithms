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
bitset<30> row, ld, rd;
int cnt;

vector<vector<int>> answers;

void backtrack(int col){
    // cout << col << "\n";
    if(col == 8){
        answers.push_back(column);
        return;
    }
    for(int r=0;r<8;r++){
        if(!row[r] and !rd[r + col] and !ld[r - col + 8 - 1]){
            row[r] = rd[r + col] = ld[r - col + 8 - 1] = true;
            column[col] = r; 
            backtrack(col+1);
            row[r] = rd[r + col] = ld[r - col + 8 - 1] = false;
        } 
    }
}

bool solve(int c){
    int n, m, i, j, k, l;
    int a, b;
    
    vector<int> v(8, -1);
    
    if(cin >> v[0]) {
        for(i=1;i<8;i++) cin >> v[i];
    }else{
        return false;
    }
    
    int mn = INT_MAX;
    for(i=0;i<answers.size();i++){
        int sum = 0;
        for(j=0;j<v.size();j++){
            sum += (answers[i][j] != v[j]-1);
        }
        // cout << sum << "\n";
        mn = min(mn, sum);
    }
    cout << "Case " << c << ": " << mn << '\n';
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
    backtrack(0);
    int caseNo = 1;
    while(solve(caseNo++));
}