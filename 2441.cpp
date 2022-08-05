#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;

    for(int i = N, j = 0; i > 0; i--, j++) {
        int tmp = j;
        while(tmp--)
            cout << " ";
        tmp = i;
        while(tmp--)
            cout << '*';
        cout << '\n';
    }
}