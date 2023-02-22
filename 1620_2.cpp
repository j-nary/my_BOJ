#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<string> v;
    v.push_back("null");
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
    }
    
    string q;
    for (int i = 0; i < M; i++) {
        cin >> q;
        int tmp = atoi(q.c_str());
        if (!tmp) {
            if (find(v.begin(), v.end(), q) != v.end()) {
                cout << find(v.begin(), v.end(), q) - v.begin() << '\n';
            }
        }
        else {
            cout << v[tmp] << '\n';
        }
    }
}