//BOJ_11659 구간 합 구하기 4 [실버 3]
//https://www.acmicpc.net/problem/11659

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100005];
int sum[100005];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        printf("%d\n", sum[b] - sum[a-1]);
    }

}