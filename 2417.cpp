//BOJ_2417 정수 제곱근 [실버 4]
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	long long N, q;
	cin >> N;
	
	q = sqrt(N);

	if ((q*q) < N) {
		++q;
	}

	cout << q << '\n';

	return 0;
}