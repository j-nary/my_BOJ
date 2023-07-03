#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int A[1003][1003];
int B[1003][1003];
int N, Q;
bool flag;
void pattern() {
    string pt; cin >> pt;
    // queue<int> q1, q2;
    if (pt == "RO") {   //홀수행 이동
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                if (i % 2 == 0) {
                    if (flag == 0) A[i][j] = B[i][j];
                    else B[i][j] = A[i][j];
                    continue;
                }
                int tmp = (j - 2) % N + 1;
                if (tmp == 0) tmp = N;
                if (flag == 0) A[i][j] = B[i][tmp];
                else B[i][j] = A[i][tmp];
            }
        }
    }

    else if (pt == "RE") {  //짝수행 이동
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                if (i % 2 == 1) {
                    if (flag == 0) A[i][j] = B[i][j];
                    else B[i][j] = A[i][j];
                    continue;
                }
                int tmp = (j - 2) % N + 1;
                if (tmp == 0) tmp = N;
                if (flag == 0) A[i][j] = B[i][tmp];
                else B[i][j] = A[i][tmp];
            }
        }
    }

    else if (pt == "CO") {  //홀수열 이동
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                if (j % 2 == 0) {
                    if (flag == 0) A[i][j] = B[i][j];
                    else B[i][j] = A[i][j];
                    continue;
                }
                int tmp = (i - 2) % N + 1;
                if (tmp == 0) tmp = N;
                if (flag == 0) A[i][j] = B[tmp][j];
                else B[i][j] = A[tmp][j];
            }
        }
    }

    else if (pt == "CE") {  //짝수열 이동
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                if (j % 2 == 1) {
                    if (flag == 0) A[i][j] = B[i][j];
                    else B[i][j] = A[i][j];
                    continue;
                }
                int tmp = (i - 2) % N + 1;
                if (tmp == 0) tmp = N;
                if (flag == 0) A[i][j] = B[tmp][j];
                else B[i][j] = A[tmp][j];
            }
        }
    }

    else if (pt == "S") {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (flag == 1) swap(A[r1][c1], A[r2][c2]);
        else swap(B[r1][c1], B[r2][c2]);
        flag = !flag;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            B[i][j] = (i-1) * N + j;
        }
    }
    for (int i = 0; i < Q; i++) {
        pattern();
        flag = !flag;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(flag) cout << A[i][j] << " ";
            else cout << B[i][j] << " ";
        }
        cout << '\n';
    }
}