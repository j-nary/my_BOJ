//BOJ_11000 강의실 배정 [골드 5]
//https://www.acmicpc.net/problem/11000
//O(n^2) 알고리즘 -> 시간초과
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; scanf("%d", &N);         //1 < N < 200,000
    vector<pair<int, int> > input;
    for (int i = 0; i < N; i++) {   //O(N)
        int s, t; 
        scanf("%d%d", &s, &t);
        input.push_back(make_pair(s, t));
    }
    sort(input.begin(), input.end());   //O(NlogN)

    vector<int> v;
    for (int i = 0; i < N; i++) {       //O(N^2)
        int s = input[i].first;
        int t = input[i].second;
        int flag = 0;
        for (int j = 0; j < v.size(); j++) {    //O(N)
            if (v[j] <= s) {
                v[j] = t;
                flag = 1;
                break;
            }
        }
        if (!flag) v.push_back(t);
    }

    printf("%d", v.size());
}