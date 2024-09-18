// BOJ_28117 prlong longf [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;
string str;

int fibo[81];
int fibonacci(int N)
{
  if (fibo[N])
    return fibo[N];
  if (N == 1)
    return fibo[N] = 1;
  if (N == 2)
    return fibo[N] = 2;

  return fibo[N] = fibonacci(N - 1) + fibonacci(N - 2);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> str;

  fibonacci(N);
  vector<int> cnt;
  int tmp = str.find("long");
  int idx = tmp;
  int curCnt = 1;
  while (tmp != -1)
  {
    tmp = str.find("long", tmp + 1);
    if (tmp == idx + 4)
    {
      curCnt++;
    }
    else
    {
      cnt.push_back(curCnt);
      curCnt = 1;
    }
    idx = tmp;
  }

  int ans = 1;
  for (int i = 0; i < cnt.size(); i++)
  {
    ans *= fibo[cnt[i]];
  }
  cout << ans << '\n';
}