#include <iostream>
#include <algorithm>

using namespace std;

int num[1003];
int neg[1003];
int main() {
    int N; cin >> N;

    int data;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> data;
        cnt = max(cnt, data);
        if (data < 0) {
            neg[-data] = 1;
            cnt = max(cnt, -data);
        }
        else num[data] = 1;
    }

    for (int i = cnt; i > 0; i--) {
        if (neg[i] != 0)
            cout << -i << " ";
    }
    for (int i = 0; i <= cnt; i++) {
        if (num[i] != 0)
            cout << i << " ";
    }
    cout << endl;
}