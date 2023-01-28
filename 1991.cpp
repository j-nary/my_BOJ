//BOJ_1991 트리 순회 [실버 1]
//https://www.acmicpc.net/problem/1991

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int Tree[30][2];

void preOrder(int n) {
    if (n == -1) return;
    cout << (char)(n + 'A');
    preOrder(Tree[n][0]);
    preOrder(Tree[n][1]);
}
void inOrder(int n) {
    if (n == -1) return;
    inOrder(Tree[n][0]);
    cout << (char)(n + 'A');
    inOrder(Tree[n][1]);
}
void postOrder(int n) {
    if (n == -1) return;
    postOrder(Tree[n][0]);
    postOrder(Tree[n][1]);
    cout << (char)(n + 'A');
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        char d, l, r;
        cin >> d >> l >> r;

        int idx = d - 'A';
        if (l == '.') Tree[idx][0] = -1;
        else Tree[idx][0] = l - 'A';

        if (r == '.') Tree[idx][1] = -1;
        else Tree[idx][1] = r - 'A';
    }

    preOrder(0); cout << '\n';
    inOrder(0); cout << '\n';
    postOrder(0); cout << '\n';
}