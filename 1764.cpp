//BOJ_1764 듣보잡 (실버 4)
//https://www.acmicpc.net/problem/1764
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    //듣도 못한 사람 N, 보도 못한 사람 M

    vector<string> v;   //듣도 못한 사람
    vector<string> res; //듣도 보도 못한 사람 


    for (int i = 0; i < N; i++) {
        string tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < M; i++) {
        string tmp; cin >> tmp;
        bool isFound = binary_search(v.begin(), v.end(), tmp);
        if (isFound) res.push_back(tmp);

        //시간초과
        // for (int i = 0; i < v.size(); i++) {
        //     if (tmp == v[i]) {
        //         res.push_back(tmp);
        //     }
        // }
    }

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

}