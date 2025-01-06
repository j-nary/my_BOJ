//BOJ_5052 전화번호 목록 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;
vector<int> num;

const int MAX_NXT = 10;   // 문자열 최대 길이
struct Trie {
  Trie* nxt[MAX_NXT];   // 다음 노드 가리키는 포인터 배열
  bool isAccepted;          // accepting node가 있는지 여부
  bool hasChild;        // 이 노드의 자식이 있는지 여부

  Trie() {
    fill(nxt, nxt + MAX_NXT, nullptr);
    isAccepted = hasChild = false;
  }
  ~Trie() {
    for (int i = 0; i < MAX_NXT; i++) if (nxt[i]) delete nxt[i];
  }

  // 문자열 key를 현재 노드부터 삽입
  void insert(const char* key) {
    if (*key == '\0') isAccepted = true;
    else {
      int next = *key - '0';

      // 해당 노드가 없으면 새로 동적 할당해서 생성
      if (!nxt[next]) nxt[next] = new Trie;
      hasChild = true;
      
      // 자식 노드에서 이어서 삽입
      nxt[next] -> insert(key + 1);
    }
  }

  // 일관성이 있는지 여부
  bool isConsistent() {
    // 자식이 있으면서 끝나는 전화번호도 있다면 일관성 X
    if (hasChild && isAccepted) return false;

    // 자식들 중 하나라도 일관성 없으면 이 노드도 일관성 X
    for (int i = 0; i < MAX_NXT; i++)
      if (nxt[i] && !nxt[i]->isConsistent()) return false;
    
    return true;
  }
};

void test_case() {
  cin >> N;
  num.resize(N, 0);

  Trie *root = new Trie;
  for (int i = 0; i < N; i++) {
    char phoneNumber[11];
    cin >> phoneNumber;
    root -> insert(phoneNumber);
  }

  if (root -> isConsistent()) cout << "YES\n";
  else cout << "NO\n";

  delete root;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    test_case();
  }
}