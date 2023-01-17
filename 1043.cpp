//BOJ_1043 거짓말 [골드4]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int party[52];
int visited[52];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M;   //사람 N명, 파티 M개
    cin >> N >> M;

    int knows; cin >> knows;
    queue<int> q;
    vector<int> v[52];
    for (int i = 0; i < knows; i++) {
        int tmp; cin >> tmp;
        q.push(tmp);    //1이 들어가
    }

    for (int i = 0; i < M; i++) {
        int many; cin >> many;
        for (int j = 0; j < many; j++) {
            int tmp; cin >> tmp;
            v[i].push_back(tmp);
        }
    }

    while(!q.empty()) {
        int stn = q.front();
        q.pop();
        for (int i = 0; i < M; i++) {
            if (party[i] != 1) {    //이미 탈락된 게 아니라면
                int flag = 0;
                for (int j = 0; j < v[i].size(); j++) {
                    if (v[i][j] == stn) {
                        flag = 1;
                        party[i] = 1;
                        break;
                    }
                }
                if (flag == 1) {    //같은 파티 사람들 기준 큐로 넣기
                    for (int j = 0; j < v[i].size(); j++) {
                        int idx = v[i][j];
                        if (visited[idx] == 0) {
                            q.push(idx);
                        }
                    }
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        if (party[i] == 0) cnt++;
    }
    cout << cnt << endl;
}