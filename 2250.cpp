//BOJ_2250 트리의 높이와 너비
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool rootChk[10004];
pair<int, int> tree[10004];     //{left, right}
vector<int> level[10004];
int columnIdx[10004];           //columnIdx[8] = 1

void leveling(int d, int node) {
    level[d].push_back(node);
    if (tree[node].first != -1) leveling(d + 1, tree[node].first);
    if (tree[node].second != -1) leveling(d + 1, tree[node].second);
}

//중위순회로 열 번호 매기기
int idx = 1;
void inOrder(int n) {
    if (n == -1) return;
    inOrder(tree[n].first);
    columnIdx[n] = idx++;
    inOrder(tree[n].second);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //입력 받기
    int N; cin >> N;
    int ip1, ip2, ip3;
    for (int i = 0; i < N; i++) {
        cin >> ip1 >> ip2 >> ip3;
        tree[ip1] = {ip2, ip3};
        if (ip2 > 0) rootChk[ip2] = true;
        if (ip3 > 0) rootChk[ip3] = true;
    }

    //루트 찾기
    int root = 0;
    for (int i = 1; i <= N; i++) {
        if (!rootChk[i]) {
            root = i;
            break;
        }
    }

    //레벨 입력하기
    leveling(1, root);
    //열 번호 저장하기
    inOrder(root);

    int maxWidth = 0, maxIdx = 0;
    for (int i = 1; level[i].size() > 0; i++) {
        int tmp = columnIdx[level[i][level[i].size() - 1]] - columnIdx[level[i][0]] + 1;
        if (tmp > maxWidth) {
            maxWidth = tmp;
            maxIdx = i;
        }
    }

    cout << maxIdx << " " << maxWidth << '\n';
}