//BOJ_5430 AC [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//R : 배열 순서 뒤집는 함수
//D : 첫번째 수를 버리는 함수 (empty -> error)
// 0 1 2 3 4 5 6 7
// [ 1 , 2 , 3 , 4 ]

void test_case() {
    string P; cin >> P;
    int N; cin >> N;
    vector<string> arr;
    string input; cin >> input;
    string tmp = "";
    for (int i = 1; i < input.size(); i++) {
        if (input[i] != ']' && input[i] != ',') {
            tmp += input[i];
        } else {
            arr.push_back(tmp);
            tmp = "";
        }
    }
    bool chk[100005];
    memset(chk, 0, sizeof(chk));
    bool flag = true;
    int front = 0, back = N;
    for (int i = 0; i < P.size(); i++) {
        if (P[i] == 'R') {
            flag = !flag;
        } else {
            flag ? front++ : back--;
            if (front > N || back < 0 || front > back) {
                cout << "error" << '\n';
                return;
            } 
        }
    }

    cout << "[";
    // front ~ back-1
    if (flag) {
        for (int i = front; i <= back - 1; i++) {
            cout << arr[i];
            if (i != back - 1) cout << ",";
        }
    } else {
        for (int i = back - 1; i >= front; i--) {
            cout << arr[i];
            if (i != front) cout << ",";
        }
    }
    cout << "]\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}