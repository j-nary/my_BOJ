#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int crainFlag[51];
int boxFlag[10004];
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
    sort(box.begin(), box.end());   //box 오름차순 정렬

    if (crain[crain.size()-1] < box[0]) {
        cout << -1 << '\n';
        return 0;
    }

    int check = 0;
    int boxcnt = 0;
    while(boxcnt < M) {
        int cnt = 0;

        for (int i = 0; i < N && cnt < N; i++) {
            for (int j = 0; j < M; j++) {
                if (crain[i] <= box[j] && boxFlag[j] == 0) {
                    boxFlag[j] = 1;
                    cnt++;
                    boxcnt++;
                    break;
                }                
            }
            if(boxcnt == M) break;
        }        
        check++;
    }
    cout << check << '\n';
}