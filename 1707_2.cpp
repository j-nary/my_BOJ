#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define RED 1
#define BLUE 2

using namespace std;

int vtx, edg;
vector<vector<int>> v;
vector<int> isVis;

void DFS(int cur){
    if(!isVis[cur]) isVis[cur] = RED;

    for(int i = 0; i < v[cur].size(); i++){
        int next = v[cur][i];

        if(!isVis[next]){
            if(isVis[cur] == RED)   isVis[next] = BLUE;
            else if(isVis[cur] == BLUE) isVis[next] = RED;
            DFS(next);
        }
    }
}

bool isBipartite(){
    for(int cur = 1; cur <= vtx; cur++){
        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i];
            if(isVis[cur] == isVis[next])   return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    while(tc--){
        cin >> vtx >> edg;
        v.assign(vtx + 1, vector<int>(0, 0));
        isVis.assign(vtx + 1, false);

        for(int i = 0; i < edg; i++){
            int s, e;
            cin >> s >> e;
            v[s].emplace_back(e);
            v[e].emplace_back(s);
        }
        for(int i = 1; i <= vtx; i++){
            if(!isVis[i])   DFS(i);
        }
        if(isBipartite())   cout << "YES\n";
        else    cout << "NO\n";

        v.clear();
        isVis.clear();
    }
}