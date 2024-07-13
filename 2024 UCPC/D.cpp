#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node
{
  int h, a, idx;

  bool operator<(const node &rhs) const
  {
    if (h == rhs.h)
    {
      return a < rhs.a;
    }
    return h < rhs.h;
  }
};
vector<node> v;
pair<int, int> child[200005];

int calculate_depth(int index)
{
  return static_cast<int>(std::log2(index + 1)) + 1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  for (int i = 0; i <= N; i++)
  {
    child[i] = {-1, -1};
  }

  for (int i = 1; i <= N; i++)
  {
    int h, a;
    cin >> a >> h;
    v.push_back({h, a, i});
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < N; i++)
  {
    int depth = calculate_depth(i);
    if (depth != v[i].h)
    {
      cout << -1 << '\n';
      return 0;
    }
  }

  vector<pair<int, int>> current_level;
  vector<pair<int, int>> next_level;

  int index = 0;
  int depth = 1;
  current_level.push_back({v[index].a, v[index++].idx});

  while (!current_level.empty())
  {
    // 현재 깊이의 노드 출력
    // cout << "Depth: " << depth << '\n';

    // 다음 깊이의 노드를 next_level에 담기
    next_level.clear();
    for (auto &node : current_level)
    {
      int left_index = 2 * index - 1; // 왼쪽 자식의 인덱스
      int right_index = 2 * index;    // 오른쪽 자식의 인덱스

      if (left_index < N)
      {
        next_level.push_back({v[left_index].a, v[left_index].idx});
      }
      if (right_index < N)
      {
        next_level.push_back({v[right_index].a, v[right_index].idx});
      }
      ++index;
    }

    if (next_level.empty())
      break;
    for (int i = 0; i < next_level.size(); i++)
    {
      int parent_index = (i - 1) / 2;
      if (i % 2 == 0)
      { // left child
        if (current_level[parent_index].first < next_level[i].first)
        {
          cout << -1 << '\n';
          return 0;
        }
        child[current_level[parent_index].second].first = next_level[i].second;
      }
      else
      { // right child
        if (current_level[parent_index].first > next_level[i].first)
        {
          cout << -1 << '\n';
          return 0;
        }
        child[current_level[parent_index].second].second = next_level[i].second;
      }
    }

    // current_level을 next_level로 업데이트
    current_level = next_level;
    depth++;
  }

  for (int i = 1; i <= N; i++)
  {
    cout << child[i].first << " " << child[i].second << '\n';
  }
}

// 50(1)30(2)70(3)20(4)40(5)60(6)80(7)

    //  2
    // 1 3

    // 2-   2 4
    // 3- 1  3 5 6

    // height * 2

    // 1 - 1 2

    // 2 - 2 1
    // 3 - 2 3

    // 4 - 3
    // 5 - 3
    // 6 - 3
    // 7 - 3

    // 8 - 4
    // 9 - 4

    // 2 ^ height - 1

    // 절반으로 나눠서 작은 것중에 큰게 제일 큰 것보다 작아야됨 2 ^ (3 - 1)

    //     200 100 300
    // 1 1

    // 5 2
    // 4 2

    // 2 3
    // 6 3
    // 3 3
    // 7 3

    // 8 4
    // 9 4
    // 10 4
    // 11 4
    // 12 4
    // 13 4
    // 14 4
    // 15 4