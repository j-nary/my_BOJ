#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool sosu[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, K; cin >> N >> K;
    
    sosu[1] = true;
    int cnt = 0;
    
    for (int i = 2; i <= N; i++) {
        if (sosu[i] == true) continue;
        else {
            for (int j = i; j <= N; j++) {
                if (j % i == 0 && sosu[j] == false) {
                    sosu[j] = true;
                    cnt ++;
                    if (cnt == K) {
                        cout << j << '\n';
                        return 0;
                    }
                }
            }
        }
    }
}