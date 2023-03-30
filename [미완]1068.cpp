//BOJ_1068 트리 [골드 5]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v;
int check[51];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    int root = -1;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
        if (input == -1) root = i;
        else check[input]++;
    }
    int delete; cin >> delete;

    int leaf = 0;
    for (int i = 0; i < N; i++) {
        if (check[i] == 0) leaf++;
    }

}