#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<pair<int, string>> v;

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string tmp; cin >> tmp;
        v.push_back(make_pair(i, tmp));
    }

    while(M--) {
        string input;
        cin >> input;

        if (input[0] > 64 && input[0] < 123)
            for (int i = 0; i < N; i++) {
                if (input == v[i].second) {
                    cout << v[i].first << '\n';
                    break;
                }
            }
        else {
            int tmp = stoi(input);
            cout << v[tmp+1].second << '\n';
        }
    }
}