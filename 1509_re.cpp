//BOJ_1509 팰린드롬 분할 [골드 1]
//PS 시험대비 다시 풀기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool dp[2502][2502];
//dp[i][j] : i번째부터 j번째까지의 문자열이 팰린드롬인지의 여부
int cnt[2502];
//cnt[i] : 0번째부터 i번째까지의 문자열의 팰린드롬 분할 수의 최솟값
vector<char> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string input; cin >> input;
    int N = input.length();
    for (int i = 0; i < N; i++) {
        v.push_back(input[i]);
    }

    for (int diagonal = 0; diagonal < N; diagonal++) {
        for (int i = 0; i < N; i++) {
            int j = i + diagonal;

            //길이가 1일 때
            if (i == j) dp[i][j] = true;
            //길이가 2일 때
            else if (i + 1 == j) dp[i][j] = (v[i] == v[j]);
            //길이가 3이상일 때
            else dp[i][j] = (v[i] == v[j] && dp[i+1][j-1]);
        }
    }

    for (int j = 0; j < N; j++) {
        cnt[j] = 1e9;
        for (int i = 0; i <= j; i++) {
            if (!dp[i][j]) continue;
            cnt[j] = min(cnt[j], cnt[i - 1] + 1);
        }
    }

    cout << cnt[N - 1] << '\n';
}