//BOJ_1629 곱셈 [실버 1]
//https://www.acmicpc.net/problem/1629
//시간초과 B번 돌면 안 돼

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int A, B, C; cin >> A >> B >> C;
    int res = 1;
    for (int i = 0; i < B; i++) {
        res *= A;
        res %= C;
    }

    cout << res << endl;
}