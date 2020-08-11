#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 100000000000000000
#define all(x) (x).begin(), (x).end()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))

void printv(vector<int> & v) {for(auto ele : v) cout << ele+1 << " "; cout << "\n";}
double dist, cap, mpg, c0;
vector<double> dists(52), costs(52);
double sum;
double mn = INF;

void backtrack(double existing, int idx){
    if(dists[idx] == dist) {
        mn = min(mn, sum);
        return;
    }
    double gallons_to_go_next = (dists[idx+1] - dists[idx]) / mpg;
    if(gallons_to_go_next > cap) return;
    if(existing * 2 <= cap or (existing * 2 > cap and gallons_to_go_next > existing)){
        sum += costs[idx] * (cap - existing) + 200;
        backtrack(cap - gallons_to_go_next, idx + 1);
        sum -= (costs[idx] * (cap - existing) + 200);
        if(existing >= gallons_to_go_next)
            backtrack(existing - gallons_to_go_next, idx + 1);
    }else{
        backtrack(existing - gallons_to_go_next, idx + 1);
    }

}

bool solve(int c){
    int i = 1, j, k;
    sum = 0;
    mn = INF;
    cin >> dist;
    if(dist < 0) return false;
    int q;
    cin >> cap >> mpg >> c0 >> q;
    dists[0] = 0;
    costs[0] = c0*100;
    while(q--){
        cin >> dists[i] >> costs[i];
        i++;
    }
    dists[i] = dist;
    sum = costs[0];
    backtrack(cap - dists[1] / mpg, 1);
    cout << "Data Set #" << c << "\n";
    cout << fixed << setprecision(2) << "minimum cost = $" << mn / 100 << '\n';
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