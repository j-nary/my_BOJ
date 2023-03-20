//BOJ_11049 행렬 곱셈 순서 [골드 3]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[502]; //d[i-1]과 d[i]는 i번째 행렬의 행과 열
int M[502][502];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    int r, c;
    cin >> r >> c;
    d[0] = r; d[1] = c;
    for (int i = 2; i <= N; i++) {
        cin >> r >> c;
        d[i] = c;
    }

    for (int diagonal = 1; diagonal <= N - 1; diagonal++) {
        for (int i =1; i <= N - diagonal; i++) {
            int j = i + diagonal;
            M[i][j] = M[i][i] + M[i+1][j] + d[i-1]*d[i]*d[j];
            for (int k = i + 1; k <= j - 1; k++) {
                int tmp = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
                if (M[i][j] > tmp) M[i][j] = tmp;
            }
        }
    }

    cout << M[1][N] << '\n';
}