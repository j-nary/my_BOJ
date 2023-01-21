//BOJ_14425 문자열 집합 [실버 3]
//https://www.acmicpc.net/problem/14425

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<string> v;  
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        string tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < M; i++) {
        string tmp; cin >> tmp;
        bool isFound = binary_search(v.begin(), v.end(), tmp);
        if (isFound) cnt++;
    }

    cout << cnt << endl;

}