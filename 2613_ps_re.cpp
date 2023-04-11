//BOJ_2613 숫자구슬 [골드 2]
//PS 시험대비 다시 풀기
//Parametric Search로 풀기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> gu;
int N, M;

vector<int> promising(int maxSum) {
    vector<int> ret;
    int tmp = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        tmp += gu[i];
        if (tmp > maxSum) {
            tmp = gu[i];
            ret.push_back(cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    ret.push_back(cnt);
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M;
    int left = 0, right = 0;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        gu.push_back(input);
        left = max(left, input);
        right += input;
    }

    vector<int> res;
    int firstAns = 1e9;
    while (left <= right) {
        int mid = (left + right) / 2;

        vector<int> tmp = promising(mid);

        if (tmp.size() <= M) {
            right = mid - 1;
            if (firstAns > mid) {
                firstAns = mid;
                res = tmp;
            }
        }
        else {
            left = mid + 1;
        }
    }

    cout << firstAns << '\n';
    if (res.size() != M) {
        while (res.size() != M) {
            for (int i = 0; i < res.size(); i++) {
                if (res[i] > 1) {
                    res[i]--;
                    res.insert(res.begin(), 1);
                    break;
                }
            }
        }  
    }
    for (int i = 0; i < M; i++) {
        cout << res[i] << " ";
    }
    cout << '\n';
}