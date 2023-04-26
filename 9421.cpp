#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

bool sosu[1000006];	//false면 소수
bool chk[1000006];
bool sgs(int num) {
	memset(chk, 0, sizeof(chk));
	while (!chk[num]) {
		if (num == 1) return true;
		chk[num] = true;
		string s = to_string(num);
		num = 0;
		int tmp = 0;
		for (int i = 0; i < s.length(); i++){
			tmp = s[i]-'0';
			num += (tmp * tmp);
		}
	}
	return false;
} 
int main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;
	
	//소수 판정
	sosu[1] = true;
	for (int i = 2; i * i < 1000006; i++) {
		if (sosu[i]) continue;
		for (int j = i + i; j < 1000006; j += i) {
			sosu[j] = true;
		}
	} 
	
	for (int i = 2; i <= N; i++) {
		if (!sosu[i] && sgs(i)) cout << i << '\n';
	}
}
