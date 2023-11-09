//BOJ_16562 친구비 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int price[10004];
int parent[10004];
// int lowPrice[10004];
int find(int a) {
    if (!parent[a]) return a;
    return parent[a] = find(parent[a]);
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    parent[b] = a;
    price[a] = min(price[a], price[b]);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M, k;
    cin >> N >> M >> k;

    for (int i = 1; i <= N; i++) {
        cin >> price[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        merge(a, b);
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (find(i) == i) {
            sum += price[i];
        }
    }

    if (sum > k) cout << "Oh no\n";
    else cout << sum << '\n';
}