//BOJ_18310 안테나 [실버 3]
//https://www.acmicpc.net/problem/18310

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    vector<int> v;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += abs(v[i] - 1);
    }
    long long minSum = sum;
    int idx = 0;
    
    for (int atn = 2; atn <= v.back(); atn++) {
        long long nsum = 0;
        for (int i = 0; i < N; i++) {
            nsum += abs(v[i] - atn);
        }
        if (minSum > nsum) {
            minSum = nsum;
            idx = atn;
        }
    }

    cout << idx << '\n';
}