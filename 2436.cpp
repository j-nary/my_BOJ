//BOJ_2436 공약수 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int GCD(int a, int b) {
		int c;
		while (b != 0) {
				c = a % b;
				a = b;
				b = c;
		}
		return a;
}

struct node {
  int a, b;
  bool operator<(const node& other) const {
    return this->a + this->b < other.a + other.b;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int gcd, lcm;
  cin >> gcd >> lcm;

  // a * b = gcd * lcm
  // a = gcd * X
  // b = gcd * Y
  // gcd(X, Y) = 1, X * Y = lcm / gcd

  int K = lcm / gcd;
  int X = 1, Y = K;

  vector<node> ans;
  for (int i = 1; i * i <= K; i++) {
    if (K % i) continue;
    if (GCD(i, K / i) == 1) ans.push_back({gcd * i, gcd * (K / i)});
  }

  sort(ans.begin(), ans.end());

  cout << ans[0].a << ' ' << ans[0].b << '\n';
}