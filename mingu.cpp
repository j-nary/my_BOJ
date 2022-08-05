#include <cstdio>

using namespace std;
using ll = long long;

const int N = 1e6 + 6;

ll tree[4 * N], lazy[4 * N], arr[N];

void propogation(int node, int s, int e) {
    if (!lazy[node]) return;
    if (s != e) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }
    tree[node] += (e - s + 1) * lazy[node];
    lazy[node] = 0;
}

ll query(int node, int s, int e, int qs, int qe) {
    propogation(node, s, e);
    if (e < qs || qe < s) return 0;
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) / 2;
    return query(2 * node, s, mid, qs, qe) + query(2 * node + 1, mid + 1, e, qs, qe);
}

void update(int node, int s, int e, int qs, int qe, int k) {
    propogation(node, s, e);
    if (e < qs || qe < s) return;
    if (qs <= s && e <= qe) {
        lazy[node] += k;
        propogation(node, s, e);
        return;
    }
    int mid = (s + e) / 2;
    update(2 * node, s, mid, qs, qe, k);
    update(2 * node + 1, mid + 1, e, qs, qe, k);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void init(int node, int s, int e) {
    if (s == e) {
        tree[node] = arr[s];
        return;
    }
    int mid = (s + e) / 2;
    init(2 * node, s, mid);
    init(2 * node + 1, mid + 1, e);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", arr + i);
    init(1, 0, N);
    for (int i = 0; i < m + k; i++) {
        int a; scanf("%d", &a);
        if (a == 1) {
            int b, c, d; scanf("%d %d %d", &b, &c, &d);
            update(1, 0, N, b, c, d);
        } else {
            int b, c; scanf("%d %d", &b, &c);
            printf("%lld\n", query(1, 0, N, b, c));
        }
    }
}