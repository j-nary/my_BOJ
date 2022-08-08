#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int flag[51];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;

    cin >> N;
    vector<int> crain;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        crain.push_back(tmp);
    }

    cin >> M;
    vector<int> box;
    for (int i = 0; i < M; i++) {
        int tmp; cin >> tmp;
        box.push_back(tmp);
    }

    sort(crain.begin(), crain.end());   //crain 오름차순 정렬
    sort(box.begin(), box.end());   //box 내림차순 정렬
    reverse(box.begin(), box.end());

    if (crain[crain.size()-1] < box[0]) {
        cout << -1 << '\n';
        return 0;
    }

    int check = 0;
    while(!box.empty()) {
        int cnt = 0;
        memset(flag, 0, sizeof(flag));
        for (int i = 0; cnt < N && i < box.size(); i++) {
            for (int j = N-1; j >= 0; j--) {
                if (box[i] <= crain[j] && flag[j] == 0) {
                    cnt++;
                    box.erase(box.begin() + i);
                    i--;
                    flag[j] = 1;
                    break;
                }
            }
            if(box.empty()) break;
        }
        check++;
    }
    cout << check << '\n';
}