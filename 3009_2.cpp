//BOJ_3009 네 번째 점 [브론즈 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int x[1003];
int y[1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int x1, x2, y1, y2;
    int xflag = 0, yflag = 0;
    cin >> x1 >> y1;

    int a, b; cin >> a >> b;
    if (x1 == a) {
        xflag = 1;
    } else if (x1 != a) {
        x2 = a;
    }
    if (y1 == b) {
        yflag = 1;
    } else if (y1 != b) {
        y2 = b;
    }

    cin >> a >> b;
    if (a == x1) {
        xflag = 2;
    } else if (a == x2) {
        xflag = 1;
    }
    if (b == y1) {
        yflag = 2;
    } else if (b == y2) {
        yflag = 1;
    }

    if (xflag == 1) {
        cout << x1 << " ";
    } else if (xflag == 2) {
        cout << x2 << " ";
    }

    if (yflag == 1) {
        cout << y1 << "\n";
    } else if (yflag == 2) {
        cout << y2 << "\n";
    }
}