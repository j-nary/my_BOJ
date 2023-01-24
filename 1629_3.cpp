//BOJ_1629 곱셈 [실버 1]
//https://www.acmicpc.net/problem/1629
//분할 정복을 어떻게 적용해야하는 지를 습득한 문제

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long A, B, C;
int power(long long idx) {
    if (idx == 0) return 1;
    if (idx == 1) return A % C;

    long long k = power(idx/2);

    long long res = 1;
    res *= k;
    res %= C;
    res *= k;
    res %= C;

    if (idx % 2) {    //홀수
        res *= A;
        res %= C;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> A >> B >> C;
    cout << power(B) << endl;
}