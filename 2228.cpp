#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

vector<int> v;
//인접하지 않은 구간합의  최댓값
int dp[102][52];
//dp[i][j] : i번째까지의 input을 j개의 구간으로 나눴을 때의 합의 최댓값 
int main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int N; cin >> N; int input; cin >> input;
	v.push_back(input);
	for (int i = 1; i < N; i++) {
		cin >> input;
		v[i] = v[i - 1] + input;
	}
	//구간합을 3개이상으로 나누는 방법은 모르겠다... 
}
