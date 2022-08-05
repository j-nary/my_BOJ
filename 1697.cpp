#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
queue <int> q;
int arr[100005];

void BFS(int N, int K) {
    q.push(N);
    arr[N] = 1;
    while (1) {
        int cur = q.front();
        if (cur == K) break;
        q.pop();
        if (cur * 2 <= 100000 && arr[cur * 2] == 0) {
            q.push(cur * 2);
            arr[cur * 2] = arr[cur] + 1;
        }
        if (cur + 1 <= 100000 && arr[cur + 1] == 0) {
            q.push(cur + 1);
            arr[cur + 1] = arr[cur] + 1;
        }
        if (cur - 1 >= 0 && arr[cur - 1] == 0) {
            q.push(cur - 1);
            arr[cur - 1] = arr[cur] + 1;
        }
    }
    printf("%d\n", arr[K] - 1);
    return;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    BFS(N, K);
    return 0;
}