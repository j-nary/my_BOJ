//BOJ_2352 반도체 설계 [골드 2]
//확인해볼 게 있어서 다시 풀어봄
//안 되네...
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> lis;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
    }

    lis.push_back(v[0]);
    for (int i = 1; i < N; i++) {
        if (lis.back() < v[i]) {
            lis.push_back(v[i]);
        } else if (lis.back() > v[i] && lis[lis.size()-2] < v[i]){
            lis[lis.size() - 1] = v[i];
        }
    }
    cout << lis.size() << '\n';
}