//BOJ_3085 사탕 게임 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

char Bom[52][52];
char nBom[52][52];
int N, ans;

void Yummy() {
    bool flag = false;
    //행에서의 최대개수 세기
    for (int i = 0; i < N; i++) {
        int sum = 1;
        char idx = nBom[i][0];
        for (int j = 1; j < N; j++) {
            if (nBom[i][j] == idx) {
                sum++;
                ans = max(ans, sum);
            }
            else {
                sum = 1;
                idx = nBom[i][j];
            }
        }
    }

    //열에서의 최대개수 세기
    for (int j = 0; j < N; j++) {
        int sum = 1;
        char idx = nBom[0][j];
        for (int i = 1; i < N; i++) {
            if (nBom[i][j] == idx) {
                sum++;
                ans = max(ans, sum);
            }
            else {
                sum = 1;
                idx = nBom[i][j];
            }
        }
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Bom[i][j];
        }
    }

    copy(&Bom[0][0], &Bom[0][0] + 52 * 52, &nBom[0][0]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (nBom[i][j] != nBom[i][j + 1]) {
                swap(nBom[i][j], nBom[i][j + 1]);
                Yummy();
                copy(&Bom[0][0], &Bom[0][0] + 52 * 52, &nBom[0][0]);
            }
        }
    }
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N - 1; i++) {
            if (nBom[i][j] != nBom[i + 1][j]) {
                swap(nBom[i][j], nBom[i + 1][j]);
                Yummy();
                copy(&Bom[0][0], &Bom[0][0] + 52 * 52, &nBom[0][0]);
            }   
        }
    }
    cout << ans << '\n';
}