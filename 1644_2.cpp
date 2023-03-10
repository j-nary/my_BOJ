//BOJ_1644 소수의 연속합 [골드 3]
//투포인터 -> 구간합이어야한다고 !!!
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sosu[4000006]; //false면 소수
vector<int> itrSum;   //구간합 저장
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    //소수 판정
    sosu[0] = sosu[1] = true;
    for (int i = 2; i*i <= N; i++) {
        if (sosu[i] == true) continue;
        for (int j = i + i; j <= N; j+=i) {
            sosu[j] = true;
        }
    }
    //소수 찾기
    for (int i = 2; i <= N; i++) {
        if (!sosu[i]) itrSum.push_back(i);
    }

    //소수 구간합 구하기
    for (int i = 1; i < itrSum.size(); i++) {
        itrSum[i] += itrSum[i-1];
    }

    //투포인터 사용
    int cnt = 0;
    int lIdx = -1, rIdx = 0;

    while(rIdx != itrSum.size()) {
        int len = 0;
        if (lIdx < 0) len = itrSum[rIdx];
        else len = itrSum[rIdx] - itrSum[lIdx];

        if (len == N) cnt++;

        if (len > N) lIdx++;
        else rIdx++;        
    }
    cout << cnt << '\n';

}

