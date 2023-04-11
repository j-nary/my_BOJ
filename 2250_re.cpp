//BOJ_2250 트리의 높이와 너비
//PS 중간고사 대비 과제 다시 풀기

#include <iostream>
#include <algorithm>
//#include <cstring>
#include <vector>

using namespace std;

pair<int, int> tree[10004];
bool rtChk[10004];
vector<int> level[10004];
int cIdx[10004];

void leveling(int depth, int p) {
	if (p <= 0) return;
	level[depth].push_back(p);
	leveling(depth + 1, tree[p].first);
	leveling(depth + 1, tree[p].second);
}

int cnt = 1;
void inOrder(int n) {
	if (n <= 0) return;
	inOrder(tree[n].first);
	cIdx[n] = cnt++;
	inOrder(tree[n].second);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int rt, l, r;
		cin >> rt >> l >> r;
		tree[rt] = {l, r};
		if (l != -1) rtChk[l] = true;
		if (r != -1) rtChk[r] = true;
	}

	//루트 찾기
	int root = 0;
	for (int i = 1; i <= N; i++) {
		if (!rtChk[i]) {
			root = i;
			break;
		}
	}

	//레벨링 하기
	leveling(1, root); 
	//각 노드에 열 번호 매기기 
	inOrder(root);
	
	int maxLevel = 0, maxWidth = 0;
	for (int i = 1; level[i].size() > 0; i++) {
		int s = level[i][0];
		int e = level[i][level[i].size() - 1];
		if (cIdx[e] - cIdx[s] + 1 > maxWidth) {
			maxWidth = cIdx[e] - cIdx[s] + 1;
			maxLevel = i;
		}
	}
	
	cout << maxLevel << " " << maxWidth << '\n';
}