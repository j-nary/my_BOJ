#include <bits/stdc++.h>
#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct rule{
  int sx;
  int sy;
  int ex;
  int ey;
  int w;
};

int N, answer;
rule position[2501];
int cmp(rule a, rule b){
  return a.w < b.w;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  cin>>N;
  for(int i =0; i < N; i++){
    cin>>position[i].sx>>position[i].sy>>position[i].ex>>position[i].ey>>position[i].w;
  }
  sort(position,position+N, cmp);

  for(int i =0;i<N-1; i++){
    int count = 0;
    int a = position[i].sx;
    int b = position[i].sy;
    int c = position[i].ex;
    int d = position[i].ey;
    int weight = position[i].w;
    for(int j = i+1; j<N; j++){
      int e = position[j].sx;
      int f = position[j].sy;
      int g = position[j].ex;
      int h = position[j].ey;
      if((e<=c && g>=a) && (b<=h && f<=d)){
        count++;
      }
    }
    answer += (count+1) * weight; 
  }
  answer+= position[N-1].w;
  // for(int i =0; i<N; i++){
  //   cout<<position[i].sx<<position[i].sy<<position[i].ex<<position[i].ey<<position[i].w<<endl;
  // }
  cout<<answer<<'\n';
}