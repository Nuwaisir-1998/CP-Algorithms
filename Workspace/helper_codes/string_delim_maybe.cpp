#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    map<string, int> groceries;

    vector<string> list;

    int max;
    cin >> max; cin.ignore();
    string sList;
    getline(cin, sList);

    std::istringstream ss(sList);
    std::string w;
    while (std::getline(ss, w, ',')) {
        list.push_back(w);
    }

    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string str;
        getline(cin, str);

        int sub = str.find(",");

        pair<string,int> h = make_pair(str.substr(0,sub), stoi(str.substr(sub+1, str.size()-1)));

        groceries.insert(h);
    }

    int cost = 0;

    for (string a : list) {
        cost += groceries.at(a);
    }

    cout << ((cost<=max)?"true":"false") << endl;
    cout << abs(max-cost) << endl;
}