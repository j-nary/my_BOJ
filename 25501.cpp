//BOJ_25501 재귀의 귀재 [브론즈 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int cnt;

int recursion(const char *s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cnt = 0;
        char s[1003]; cin >> s;
        cout << isPalindrome(s) << " " << cnt << '\n';
    }
}