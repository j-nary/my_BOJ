#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

vector<int> v;
int main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int N, M; cin >> N >> M;
	long long input;
	long long left = 0, right = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
		right += input;
		left = max(left, input);
	}
	
	long long ans = pow(2, 33);
	long long sum = 0;
	long long mid = 0;
	while(left <= right) {
		mid = (left + right) / 2;
		
		int cnt = 1;
		sum = 0;
		for (int i = 0; i < N; i++){
			sum += v[i];
			if (sum > mid) {
				cnt++;
				sum = v[i];
			}
		}
		
		if (cnt <= M) {
			ans = min(ans, mid);
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	
	cout << ans << '\n';
}
