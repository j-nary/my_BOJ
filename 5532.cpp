#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;
    int kor = A / C + 1;
    int mth = B / D + 1;
    if (A % C == 0) kor -= 1;
    if (B % D == 0) mth -= 1;

    cout << L - max(kor, mth) << '\n';
}