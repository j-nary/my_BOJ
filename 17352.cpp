//BOJ_17352 여러분의 다리가 되어 드리겠습니다! [골드5]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int island[300005];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    queue<int> q;
    vector<int> v[N + 1];
    for (int i = 0; i < N - 2; i++) {
        int p, q; cin >> p >> q;
        v[p].push_back(q);
        v[q].push_back(p); //여기가 왜 문제지?
    }

    island[1] = 1;
    q.push(1);

    while(!q.empty()){
        int stn = q.front();
        q.pop();
        
        for (int i = 0; i < v[stn].size(); i++) {
            int tmp = v[stn][i];
            if (island[tmp] != 1) {
                island[tmp] = 1;
                q.push(tmp);
            }
        }
    }

    int target = 0;
    for (int i = 2; i <= N; i++) {
        if (island[i] == 0) {
            target = i;
            break;
        }
    }

    cout << 1 << " " << target << endl;

}