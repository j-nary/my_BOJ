//BOJ_10866 덱 [실버 4]
//https://www.acmicpc.net/problem/10866

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> v;
    int N; cin >> N;
    int input; string order; 
    while(N--) {
        cin >> order;
        if (order == "push_back") {
            cin >> input;
            v.push_back(input);
        }
        else if (order == "push_front") {
            cin >> input;
            v.insert(v.begin(), input);
        }
        else if (order == "pop_front") {
            if (v.empty()) cout << -1 << '\n';
            else {
                cout << v[0] << '\n';
                v.erase(v.begin());
            }
        }
        else if (order == "pop_back") {
            if (v.empty()) cout << -1 << '\n';
            else {
                cout << v[v.size() - 1] << '\n';
                v.erase(v.end() - 1);
            }
        }
        else if (order == "size") {
            cout << v.size() << '\n';
        }
        else if (order == "empty") {
            if (v.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (order == "front") {
            if (v.empty()) cout << -1 << '\n';
            else {
                cout << v[0] << '\n';
            }
        }
        else if (order == "back") {
            if (v.empty()) cout << -1 << '\n';
            else {
                cout << v[v.size() - 1] << '\n';
            }
        }
    }
}