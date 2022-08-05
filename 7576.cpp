#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int map[1003][1003];
typedef struct {
    int Y;
    int X;
} T;
queue<T> q;
bool check[1003][1003];
int dist[1003][1003];

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            scanf("%d", &map[i][j]);
    }

    for (int i = 1; i <= N; i++)
        for (int j =1; j <= M; j++)
            if (map[i][j] == 1)  {
                q.push({i,j});
                check[i][j] = 1;
            }
            else if (map[i][j] == -1)
                check[i][j] = true;
    while (!q.empty()){
        int a = q.front().Y;
        int b = q.front().X;
        q.pop();
        if (a != 1 && check[a-1][b] == false) {
            q.push({a-1, b});
            dist[a-1][b] = dist[a][b] + 1;
            check[a - 1][b] = true;
        }
        if (a != N && check[a+1][b] == false) {
            q.push({a+1, b});
            dist[a+1][b] = dist[a][b] + 1;
            check[a + 1][b] = true;
        }
        if (b != 1 && check[a][b-1] == false) {
            q.push({a, b - 1});
            dist[a][b-1] = dist[a][b] + 1;
            check[a][b-1] = true;
        }
        if (b != M && check[a][b+1] == false) {
            q.push({a, b + 1});
            dist[a][b+1] = dist[a][b] + 1;
            check[a][b+1] = true;
        }
    }

    int max = 0;
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= M; j++) {
            if (check[i][j] == false) {
                printf("-1");
                return 0;
            }
            if ( max < dist[i][j])
                max = dist[i][j];
        }
    printf("%d\n", max);
    return 0;
}