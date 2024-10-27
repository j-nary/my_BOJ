#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n, m, s;
string up;
char map[55][55];
int ansAlpha[26];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

vector <char> ans;

bool check(){
  int alpha[26] = {0, };
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      char now = map[i][j];
      cout<<now;
      if(now == '0') continue;
      alpha[now-'a']++;
    }
    cout<<"\n";
  }

  bool flag = true;
  for(int i = 0; i < 26; i++){
    if(ansAlpha[i] - alpha[i] > 0) flag = false;
    cout<<ansAlpha[i]<<" "<<alpha[i]<<"\n";
  }cout<<"\n";

  return flag;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin>>n>>m>>s;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin>>map[i][j];
    }
  }
  
  cin>>up;
  for(int i = 0; i < up.size(); i++){
    ansAlpha[up[i] - 'a']++;
  }

  int y = 1;
  int x = 1;

  // 강화하기
  int cnt = 0;
  int idx = 0;
  while(true){
    // 강화
    if(idx == up.size()){
      cnt++;
      idx = 0;
    }

    if(check() == false){
        break;
    }

    // 지점으로 이동.
    if(map[y][x] != up[idx]){
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
          if(map[i][j] == up[idx]){
            while(i > y){
              y++;
              ans.push_back('D');
            }while(i < y){
              y--;
              ans.push_back('U');
            }while(j > x){
              x++;
              ans.push_back('R');
            }while(j < x){
              x--;
              ans.push_back('L');
            }
          }
        }
      }
    }

    ans.push_back('P');
    ansAlpha[map[y][x]-'a']--;
    map[y][x] = '0';
    
    idx++;
  }

  cout<<cnt<<" ";

  // 목표 지점까지 이동
  while(true){
    if(y < n){
      y++;
      ans.push_back('D');
    }
    if(x < m){
      x++;
      ans.push_back('R');
    }

    if(y == n && x == m){
      break;
    }
  }

  cout<<ans.size()<<"\n";
  for(auto i: ans){
    cout<<i;
  }

  return 0;
}