//BOJ_115732 도토리 숨기기 [골드 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node {
    int A, B, C;
    //A번부터 B번 방까지 C개 간격으로 도토리 하나씩 넣기
};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K, D;    //상자, 규칙, 도토리
    cin >> N >> K >> D;
    vector<node> R;
    for (int i = 0; i < K; i++) {
        int a, b, c; cin >> a >> b >> c;
        R.push_back({a, b, c});
    }

    //박스번호 이하에 몇 개의 도토리가 있는지 파악
    int ans = 0; //상자번호 최댓값
    int left = 1, right = N;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;

        for (int i = 0; i < K; i++) {
            if (cnt >= D) break;
            //마지막 도토리 보다 시작점이 큰 규칙
            if (R[i].A > mid) continue;
            cnt += (min(mid, R[i].B) - R[i].A)/R[i].C + 1;
        }

        if (cnt >= D) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
}