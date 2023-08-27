//BOJ_12100 2048(Easy) [골드 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int N, ans;

bool arrayEqual(int NB[22][22], int B[22][22]) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (NB[i][j] != B[i][j]) return false;
        }
    }

    return true;
}

//     cout << "================\n";
//     for (int i = 1; i <= N; i++) {
//         for (int j = 1; j <= N; j++) {
//             cout << NB[i][j] << " ";
//         }
//         cout << '\n';
//     }
// }
void dfs(int depth, int B[22][22]) {
    if (depth == 5) return;
    int NB[22][22];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            NB[i][j] = B[i][j];
        }
    }

    //오른쪽
    queue<int> tmp;
    for (int i = 1; i <= N; i++) {
        for (int j = N; j > 0; j--) {
            if (NB[i][j]) tmp.push(NB[i][j]);
        }

        if (tmp.size() == N) {
            queue<int> empty;
            swap(tmp, empty);
            continue;
        }
        for (int j = N; j > 0; j--) {
            if (tmp.empty()) NB[i][j] = 0;
            else {
                NB[i][j] = tmp.front();
                tmp.pop();
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = N; j > 1; j--) {
            if (NB[i][j] == NB[i][j - 1]) {

                NB[i][j] *= 2;
                ans = max(ans, NB[i][j]);
                NB[i][j - 1] = 0;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = N; j > 0; j--) {
            if (NB[i][j]) tmp.push(NB[i][j]);
        }

        if (tmp.size() == N) {
            queue<int> empty;
            swap(tmp, empty);
            continue;
        }

        for (int j = N; j > 0; j--) {
            if (tmp.empty()) NB[i][j] = 0;
            else {
                NB[i][j] = tmp.front();
                tmp.pop();
            }
        }
    }
    if (!arrayEqual(NB, B)) dfs(depth + 1, NB);

    //왼쪽
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            NB[i][j] = B[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (NB[i][j]) tmp.push(NB[i][j]);
        }

        for (int j = 1; j <= N; j++) {
            if (tmp.empty()) NB[i][j] = 0;
            else {
                NB[i][j] = tmp.front();
                tmp.pop();
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < N; j++) {
            if (NB[i][j] == NB[i][j + 1]) {

                NB[i][j] *= 2;
                ans = max(ans, NB[i][j]);
                NB[i][j + 1] = 0;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (NB[i][j]) tmp.push(NB[i][j]);
        }

        for (int j = 1; j <= N; j++) {
            if (tmp.empty()) NB[i][j] = 0;
            else {
                NB[i][j] = tmp.front();
                tmp.pop();
            }
        }
    }
    if (!arrayEqual(NB, B)) dfs(depth + 1, NB);


    //위쪽
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            NB[i][j] = B[i][j];
        }
    }
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            if (NB[i][j]) tmp.push(NB[i][j]);
        }

        for (int i = 1; i <= N; i++) {
            if (tmp.empty()) NB[i][j] = 0;
            else {
                NB[i][j] = tmp.front();
                tmp.pop();
            }
        }
    }

    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            if (NB[i][j] == NB[i + 1][j]) {

                NB[i][j] *= 2;
                ans = max(ans, NB[i][j]);
                NB[i + 1][j] = 0;
            }
        }
    }
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            if (NB[i][j]) tmp.push(NB[i][j]);
        }

        for (int i = 1; i <= N; i++) {
            if (tmp.empty()) NB[i][j] = 0;
            else {
                NB[i][j] = tmp.front();
                tmp.pop();
            }
        }
    }
    if (!arrayEqual(NB, B)) dfs(depth + 1, NB);

    //아래쪽
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            NB[i][j] = B[i][j];
        }
    }
    for (int j = 1; j <= N; j++) {
        for (int i = N; i > 0; i--) {
            if (NB[i][j]) tmp.push(NB[i][j]);
        }

        for (int i = N; i > 0; i--) {
            if (tmp.empty()) NB[i][j] = 0;
            else {
                NB[i][j] = tmp.front();
                tmp.pop();
            }
        }
    }

    for (int j = 1; j <= N; j++) {
        for (int i = N; i > 1; i--) {
            if (NB[i][j] == NB[i - 1][j]) {

                NB[i][j] *= 2;
                ans = max(ans, NB[i][j]);
                NB[i - 1][j] = 0;
            }
        }
    }

    for (int j = 1; j <= N; j++) {
        for (int i = N; i > 0; i--) {
            if (NB[i][j]) tmp.push(NB[i][j]);
        }

        for (int i = N; i > 0; i--) {
            if (tmp.empty()) NB[i][j] = 0;
            else {
                NB[i][j] = tmp.front();
                tmp.pop();
            }
        }
    }
    if (!arrayEqual(NB, B)) dfs(depth + 1, NB);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    int NB[22][22];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            cin >> NB[i][j];
            ans = max(ans, NB[i][j]);
        }
    }

    dfs(0, NB);
    cout << ans << '\n';
}