#include <iostream>
#include <string>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

int n;
int v[111];
int idx[111][111];
p dp[111][111]; //{val, height}

p f(int s, int e){ //[s, e] 범위
	if(s > e) return {0, 0};
	if(dp[s][e].x != -1) return dp[s][e];
	dp[s][e].x = 0;

	int val = 1e9+7, h = 0;

	for(int k=s+1; k<=e; k+=2){
		if(v[s] != v[k]){
			//s, k 매칭
			p a = f(s+1, k-1); //왼쪽
			p b = f(k+1, e); //오른쪽
			int dist = k - s;
			if(val > a.x + b.x + dist + (a.y + 1) * 2){
				val = a.x + b.x + dist + (a.y + 1) * 2;
				h = max(a.y+1, b.y);
				idx[s][e] = k;
			}
		}
	}
	return dp[s][e] = {val, h};
}

void trace(int s, int e){
	if(s > e) return;
	int k = idx[s][e];
	cout << s+1 << " " << k+1 << "\n";
	trace(s+1, k-1);
	trace(k+1, e);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> n >> s;
	for(int i=0; i<n; i++) v[i] = s[i] - '0';

	for(int i=0; i<n; i++) for(int j=0; j<n; j++) dp[i][j].x = -1;

	cout << f(0, n-1).x << "\n";
	trace(0, n-1);
}