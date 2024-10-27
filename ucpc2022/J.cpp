#include <bits/stdc++.h>
#include <iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;

using namespace std;
ll N;
ll arr[500001];
ll copyarr[500001];

void swap(ll a, ll b){
  ll tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  cout.tie(nullptr);

  cin>>N;
  for(int i =0;i<N;i++){
    cin>>arr[i];
    copyarr[i] = arr[i];
  }
  sort(copyarr, copyarr+N);

  for(int i =0;i<N-1 ;i++){
    for(int j =i+1; j<N; j++){
      if(arr[i]>arr[j]){
        ll num = arr[i]*arr[j];
        ll snum = sqrt(num);
        if(snum*snum == num ) //정수 판별
        {
          swap(i, j);
        }
      }
      else continue;
    }
  }
  // bool flag = true;
  // for(int i =0;i<N;i++){
  //   if(arr[i] != copyarr[i]){
  //     cout<<"NO"<<'\n';
  //     flag = false;
  //     break;
  //   }
  // }
  // if(flag) cout<<"YES"<<'\n';
  
}