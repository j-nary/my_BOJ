//BOJ_13168 내일로 여행 [골드 3]
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;
using ll = long long;

vector<ll> adj[102];
pair<ll, ll> dist[102][102];

bool isHalf(string type) {
  return type == "S-Train" || type == "V-Train";
}

bool isFree(string type) {
  return type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, R; cin >> N >> R;
  R *= 2;
  map<string, int> Location;
  for (int i = 1; i <= N; i++) {
    string loc; cin >> loc;
    Location[loc] = i;
  }

  int M; cin >> M;
  vector<int> travel(M);
  for (int i = 0; i < M; i++) {
    string t; cin >> t;
    travel[i] = Location[t];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) dist[i][j] = {0, 0};
      else dist[i][j] = {1e9, 1e9};
    }
  }

  int K; cin >> K;
  for (int i = 0; i < K; i++) {
    string type, sLoc, eLoc; cin >> type >> sLoc >> eLoc;
    ll cost; cin >> cost;
    cost *= 2;
    int s = Location[sLoc], e = Location[eLoc];

    ll tomorrowCost = cost;
    if (isFree(type)) tomorrowCost = 0;
    else if (isHalf(type)) tomorrowCost /= 2;

    dist[s][e].first = min(dist[s][e].first, cost);
    dist[s][e].second = min(dist[s][e].second, tomorrowCost);
    dist[e][s].first = min(dist[e][s].first, cost);
    dist[e][s].second = min(dist[e][s].second, tomorrowCost);
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        dist[i][j].first = min(dist[i][j].first, dist[i][k].first + dist[k][j].first);
        dist[i][j].second = min(dist[i][j].second, dist[i][k].second + dist[k][j].second);
      }
    }
  }

  int noPay = 0, pay = R;
  for (int i = 0; i < M - 1; i++) {
    noPay += dist[travel[i]][travel[i + 1]].first;
    pay += dist[travel[i]][travel[i + 1]].second;
  }

  if (noPay <= pay) cout << "No\n";
  else cout << "Yes\n";
}