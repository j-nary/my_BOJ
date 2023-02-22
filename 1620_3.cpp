#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    map<int, string> mi;
    map<string, int> ms;
    string input;
    for (int i = 1; i <= N; i++) {
        cin >> input;
        mi.insert({i, input});
        ms.insert({input, i});
    }
    
    string q;
    for (int i = 0; i < M; i++) {
        cin >> q;
        int tmp = atoi(q.c_str());
        if (!tmp) {     //문자열일 때
            cout << ms.find(q)->second << '\n';
        }
        else {
            cout << mi.find(tmp)->second << '\n';
        }
    }
}