#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[51][51];  //기준
int B[51][51];
int n, m;

void change_arr(int n, int m) {
    for (int i = n; i < n + 3; i++) {
        for (int j = m; j < m + 3; j++) {
            if (A[i][j] == 0) A[i][j] = 1;
            else A[i][j] = 0;
        }
    }
}

bool isEqual() {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                flag = 0;
                break;
            }
        }
        if (!flag) break;
    }

    return flag;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    //입력 받기
    for (int i = 0; i < n; i++) {
        string input; cin >> input;
        for (int j = 0; j < m; j++) {
            A[i][j] = input[j] - 48;
        }
    }
    for (int i = 0; i < n; i++) {
        string input; cin >> input;
        for (int j = 0; j < m; j++) {
            B[i][j] = input[j] - 48;
        }
    }

    //전제 조건
    if (n < 3 || m < 3) {
        if (isEqual()) cout << 0 << endl;
        else cout << -1 << endl;
        return 0;
    }

    //로직 start!
    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (A[i][j] != B[i][j]) {
                change_arr(i, j);
                cnt++;
            }
        }
    }

    if (isEqual()) cout << cnt << endl;
    else cout << -1 << endl;
}