#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define p pair<int, int>
#define N 110

using namespace std;

struct node {
    int y, x, t;
};

int b, n, m, ans, map[N][N];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<int> staff;
bool check[300][1000];

void input()
{
    cin >> b >> n >> m;

    memset(map, -1, sizeof(map));

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        staff.push_back(c);
        map[a][b] = i;
    }
}

void solution()
{
    queue<node> q;

    for (int i = 0; ; i++)
    {
        if (i != 0 && q.empty())
            break;

        // 선물 배치
        int cnt = q.size();

        for (int j = 0; j < cnt; j++)
        {
            node cur = q.front();
            bool res = 0;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int ny = cur.y + dir[k][0];
                int nx = cur.x + dir[k][1];

                if (ny < 0 || ny >= b || nx < 0 || nx >= b || map[ny][nx] == -1)
                    continue;

                int staff_idx = map[ny][nx];

                if (check[staff_idx][i])
                    continue;

                for (int l = i; l < i + staff[staff_idx]; l++)
                    check[staff_idx][l] = 1;

                res = 1;
                ans++;
                break;
            }

            if (!res)
                q.push(cur);
        }

        // 선물 이동
        while (!q.empty() && q.front().t == i) {
            node cur = q.front();
            q.pop();

            if (cur.y == 0)
            {
                if (cur.x < b - 1)
                    cur.x++;

                else
                    cur.y++;
            }

            else if (cur.x == b - 1)
            {
                if (cur.y < b - 1)
                    cur.y++;

                else
                    cur.x--;
            }

            else
            {
                if (cur.x > 0)
                    cur.x--;

                else
                    continue;
            }

            cur.t++;
            q.push(cur);
        }


        if (i < m)
            q.push({ 0, 0, i + 1 });
    }

    cout << ans;
}

void solve()
{
    input();
    solution();
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}