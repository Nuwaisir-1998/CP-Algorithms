#include <bits/stdc++.h>
using namespace std;

#define ll long long

string PREVIOUS_TEXT = "";
string FINISHING_TEXT = "";

void solve(ll cs){
    ll n, i, j, k, x;
    string pref = "https://google.com/search?q=";
    string s;
    string up = "<html><head><title>Saif The Bhuiyan's links</title></head><body><marquee><h1>Saif The Bhuiyan's links</h1></marquee>";
    string down = "</body></html>";
    cout << up << endl;
    string previous_word = PREVIOUS_TEXT;
    string later_word = FINISHING_TEXT;
    while(getline(cin, s)){
        // cout << "<a href=\"" << pref + previous_word + " " + s + " " + "review" << "\"" << "target=\"_blank\">" << previous_word + " " << s << " " <<  "review </a>" << endl;
        // cout << "<br>";
        cout << "<a href=\"" << pref + previous_word + " " + s << "\"" << "target=\"_blank\">" << previous_word + s + later_word << "</a>" << endl;
        cout << "<br>";
        // cout << "<a href=\"" << pref + s + " " + later_word << "\"" << "target=\"_blank\">" << s << " review </a>" << endl;
        // cout << "<br>";
    }

    cout << down << endl;
    
}

int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.html", "w", stdout);
#endif // ONLINE_JUDGE

    ll tt = 1;
    // cin >> tt;
    ll cs = 1;
    while (tt--)
        solve(cs++);
    
    return 0;
}