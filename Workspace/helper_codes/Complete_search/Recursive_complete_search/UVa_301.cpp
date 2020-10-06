#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 100000000000000000
#define all(x) (x).begin(), (x).end()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))

void printv(vector<int> & v) {for(auto ele : v) cout << ele+1 << " "; cout << "\n";}

int cap, B;
int sum;
int mx, q;

vector<int> toCnt(8);
vector<int> passengerCount(8);
vector<tuple<int,int,int>> vtp;

void backtrack(int idx){
    if(idx == q){
        mx = max(mx, sum);
        return;
    }
    backtrack(idx + 1);

    int from, to, cnt;
    tie(from, to, cnt) = vtp[idx];

    // Update the passengerCount from "from" to "to - 1" if every element doesn't cross the limit, otherwise it is not possible, so return..

    for(int i=from;i<to;i++){
        if(passengerCount[i] + cnt > cap){
            for(int j=from;j<i;j++) passengerCount[j] -= cnt;
            return;
        }
        passengerCount[i] += cnt;
    }
    sum += (to - from) * cnt;
    backtrack(idx + 1);
    sum -= (to - from) * cnt;
    for(int i=from;i<to;i++) passengerCount[i] -= cnt;
}

bool solve(int c){
    int i, x, y, z;
    
    cin >> cap >> B;
    sum = 0;
    mx = 0;
    cin >> q;
    
    vtp.clear();
    for(i=0;i<8;i++) toCnt[i] = 0;
    if(cap == 0 and B == 0 and q == 0) return false;
    for(i=0;i<q;i++){
        cin >> x >> y >> z;
        vtp.push_back(make_tuple(x, y, z));
    }

    backtrack(0);
    cout << mx << '\n';
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