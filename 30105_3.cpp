#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대 공약수(GCD) 함수
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    
    // 이빨 자국 위치 차이의 최대 공약수 구하기
    int g = X[1] - X[0];
    for (int i = 2; i < N; ++i) {
        g = gcd(g, X[i] - X[i - 1]);
    }
    
    // 최대 공약수의 약수들을 찾기
    vector<int> result;
    for (int i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            result.push_back(i);
            if (i != g / i) result.push_back(g / i);
        }
    }
    
    // 오름차순 정렬
    sort(result.begin(), result.end());
    
    // 출력
    cout << result.size() - 1 << '\n'; // k > 0인 경우만 출력해야 하므로 1 제외
    for (int i = 1; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}