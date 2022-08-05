#include <iostream>

using namespace std;

int main() {
    int cnt;
    cin >> cnt;

    int R;
    string S;

    while(cnt--) {
        cin >> R;
        cin >> S;
        for (int i = 0; i < S.length(); i++)
            for (int j = 0; j < R; j++) {
                cout << S[i];
            }
        cout << '\n';
    }
}

