#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> dp(305, vector<ll> (1005, 0));
vector<vector<ll>> cum(305, vector<ll> (1005, 0));

// Number of combinations of coins which make a certain coin, just needed
// to do some extra stuff for all kind of number of coins.

void coin_change(){
    dp[0][0] = 1;
    for(ll i=1;i<=300;i++){
        dp[i][1] = 1;
        for(ll j=i;j<=300;j++){
            for(ll k=1;k<=j;k++){
                dp[j][k + 1] += dp[j - i][k];
            }
        }
    }
   
    cum[0][0] = 1;
    for(ll i=0;i<=300;i++){
        cum[i][1] = 1;
        for(ll j=2;j<=1001;j++){
            cum[i][j] = cum[i][j-1] + dp[i][j];
        }
    }
}

void solve(string s){
    stringstream sin(s);
    string num;
    vector<ll> v;
    while(sin >> num){
        v.push_back(stoi(num));
    }
    if(v.size() == 1){
        cout << cum[v[0]][v[0]] << '\n';
    }else if(v.size() == 2){
        cout << cum[v[0]][v[1]] << "\n";
    }
    else {
        if(v[0] == 0){
            if(v[1] == 0){
                cout << 1 << '\n';
            }else {
                cout << 0 << "\n";
            }
        }else{
            if(v[0] != 0 && v[1] == 0) v[1]++;
            cout << cum[v[0]][v[2]] - cum[v[0]][v[1]-1] << "\n";
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif // ONLINE_JUDGE
    int tt; 
    // cin >> tt;
    string s;
    coin_change();
    while(getline(cin, s)){
        solve(s);
    }
}