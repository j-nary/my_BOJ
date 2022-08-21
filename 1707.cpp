#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int bpg[20004];
bool check[20004];
void test_case() {
    memset(bpg, 0, sizeof(bpg));

    vector<pair<int, int>> v;
    int flag = 0;
    int vtx, edg;
    cin >> vtx >> edg;

    for (int i = 0; i < edg; i++) {
        int dt1, dt2;
        cin >> dt1 >> dt2;
        if (dt1 >= dt2)
            v.push_back({dt1, dt2});
        else
            v.push_back({dt2, dt1});        
    }
    sort(v.begin(), v.end());

    bpg[v[0].first] = 1;   //red
    bpg[v[0].second] = -1;   //blue
    queue<pair<int, int>> q;
    q.push({v[0].first, v[0].second});
    check[0] = true;

    while(!q.empty()) {
        auto [dt1, dt2] = q.front();
        q.pop();

        if (bpg[dt1] == bpg[dt2]) {
            flag = 1;
            break;
        }  
        for (int i = 0; i < edg; i++) {
            if (check[i] == true) continue;

            if (v[i].first == dt1) {
                bpg[v[i].second] = bpg[dt1] * (-1);
                q.push({v[i].first, v[i].second});
                check[i] = true;
            }
        }
    }
    
    if (flag == 1)  cout << "NO" << endl;
    else            cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}
