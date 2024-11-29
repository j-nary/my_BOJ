#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int con[110][110], check[110][110];
int b, n, m, res;
int dist[3][2] = { {1, 0}, {0, 1}, {-1, 0} };
map<pair<int, int>, int> wtime;
int main() {
	scanf("%d %d %d", &b, &n, &m);
	for (int i = 0; i < n; i++) {
		int x, y, t;
		scanf("%d %d %d", &x, &y, &t);
		con[x + 1][y + 1] = 2, wtime[{x + 1, y + 1}] = t;
	}

	for (int T = 0; T < b * 3 + m; T++) {
		//move
		for (int i = 1; i <= b; i++)
			con[b][i - 1] = con[b][i];
		for (int i = b - 1; i >= 0; i--)
			con[i + 1][b] = con[i][b];
		for (int i = b - 1; i >= 1; i--)
			con[1][i + 1] = con[1][i];

		if (T < m)	con[1][1] = 1;
		else con[1][1] = 0;
		for (int i = 2; i < b; i++) {
			for (int j = 1; j < b; j++) {
				if (con[i][j] == 2) {
					if (check[i][j])	--check[i][j];
					if (check[i][j])	continue;
					for (int p = 0; p < 3; p++) {
						int x = i + dist[p][0], y = j + dist[p][1];
						if (con[x][y] == 1) {
							check[i][j] = wtime[{i, j}];
							con[x][y] = 0;
							res++;
							break;
						}
					}
				}
			}
		}
	}
	printf("%d\n", res);
}