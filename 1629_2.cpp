//BOJ_1629 곱셈 [실버 1]
//https://www.acmicpc.net/problem/1629
//메모리초과. 저장하지 않는 방법을 생각해보자.

#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

long long A, B, C;
long long *mul;
void cal(long long idx) {
    if (idx == 0) {
        mul[idx] = 1;
        return;
    }
    if (idx == 1) {
        mul[idx] = A;
        return;
    }

    if (!mul[idx/2]) {
        cal(idx/2);
    }
    long long half = mul[idx/2];
    mul[idx] *= half;
    mul[idx] %= C;
    mul[idx] *= half;
    mul[idx] %= C;
    if (idx % 2) {    //홀수
        mul[idx] *= A;
        mul[idx] %= C;
    }
}

void main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> A >> B >> C;
    mul = new long long[B];
    memset(mul, 1, B);
    cal(B);
    cout << mul[B] << endl;

}