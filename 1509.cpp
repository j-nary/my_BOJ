//BOJ_1509 팰린드롬 분할 [골드 1]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool dp[2502][2505];
//dp[i][j] : i번쨰부터 j번째까지 문자열이 팰린드롬인지 저장
int cnt[2502];
//cnt[i] : i번째까지의 문자열의 최소 팰린드롬 분할 수 저장

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string str; cin >> str;
    int N = str.length();

    //팰린드롬인지 아닌지 판별하기
    for (int diagonal = 0; diagonal < N; diagonal++) {
        for (int i = 0; i < N; i++) {
            int j = i + diagonal;
            
            //문자열 길이가 1일 때
            if (i == j) dp[i][j] = true;
            //문자열 길이가 2일 때
            else if (i + 1 == j) {
                if (str[i] == str[j]) dp[i][j] = true;
            } 
            //문자열 길이가 3 이상일 때
            else {
                if (str[i] == str[j] && dp[i+1][j-1] == true) dp[i][j] = true;
            }

        }
    }
    //분할횟수 구하기
    for (int j = 0; j < N; j++) {
        cnt[j] = 1e9+7;
        for (int i = 0; i < N; i++) {
            if (dp[i][j] == true) {
                cnt[j] = min(cnt[j], cnt[i - 1] + 1);
            }
        }
    }

    cout << cnt[N - 1] << '\n';
}