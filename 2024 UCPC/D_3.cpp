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

  // for (int i = 0; i < N; i++)
  // {
  //   int depth = calculate_depth(i);
  //   if (depth != v[i].h)
  //   {
  //     cout << -1 << '\n';
  //     return 0;
  //   }
  // }

  vector<pair<int, int>> current_level;
  vector<pair<int, int>> next_level;

  int index = 0;
  int depth = 1;
  current_level.push_back({v[index].a, v[index++].idx});

  while (!current_level.empty())
  {
    // 현재 깊이의 노드 출력
    // cout << "Depth: " << depth << '\n';
    next_level.clear();
    while (1)
    {
      if (v[index].h == depth + 1)
      {
        next_level.push_back({v[index].a, v[index].idx});
        index++;
      }
      else
      {
        break;
      }
    }

    if (next_level.size() > pow(2, depth))
    {
      cout << -1 << '\n';
      return 0;
    }

    if (next_level.empty())
      break;
    for (int i = 0; i < next_level.size(); i++)
    {
      bool flag = false;
      for (int j = 0; j < current_level.size(); j++)
      {
        if (child[current_level[j].second].first == -1 && next_level[i].first < current_level[j].first)
        {
          child[current_level[j].second].first = next_level[i].second;
          flag = true;
          break;
        }
        if (child[current_level[j].second].second == -1 && next_level[i].first > current_level[j].first)
        {
          child[current_level[j].second].second = next_level[i].second;
          flag = true;
          break;
        }
      }

      if (!flag)
      {
        cout << -1 << '\n';
        return 0;
      }

      // current_level을 next_level로 업데이트
      current_level = next_level;
      depth++;
    }
  }
  for (int i = 1; i <= N; i++)
  {
    cout << child[i].first << " " << child[i].second << '\n';
  }
}
