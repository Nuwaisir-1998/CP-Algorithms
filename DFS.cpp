//
// Created by Nuwaisir on 06/11/2019.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VISITED 1
#define UNVISITED 0

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi dfs_num;

vector<vii> adjList;

void dfs(int u)
{
    int i;
    dfs_num[u] = VISITED;
    for(i=0;i<(int)adjList[u].size();i++){
        ii v = adjList[u][i];
        if(dfs_num[v.first] == UNVISITED){
            dfs(v.first);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    return 0;
}