#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<int> s2, s3;
vector<string> ans;
struct node {
    int cnt;
    vector<int> str;
    vector<string> path;
    node(int c, vector<int> s, vector<string> p) {
        cnt = c; str = s; path = p;
    }
};
void bfs(int cnt, vector<int> str, vector<string> path) {
    vector<int> ns;
    vector<string> np;

    queue<node> q;
    q.push({cnt, str, path});
    while(!q.empty()) {
        cnt = q.front().cnt;
        str = q.front().str;
        path = q.front().path;
        q.pop();

        //종료조건
        if (cnt >= 10004) continue;
        if (str == s2 || str == s3) {
            ans = path;
            return;
        }

        //하나로 합치기
        for (int i = 0; i < str.size() - 1; i++) {
            ns = str;
            int tmp = (str[i] + str[i + 1]) * (-1);
            ns.erase(ns.begin() + i);
            ns[i] = tmp;

            np = path;
            tmp = i + 1;
            string st = "1 ";
            st += to_string(tmp);
            st.push_back(' ');
            tmp++;
            st += to_string(tmp);
            np.push_back(st);

            q.push({cnt + 1, ns, np});
        }
        
        //둘로 쪼개기
        for (int i = 0; i < str.size(); i++) {
            int tmp = str[i];
            for (int j = -1; j <= 1; j++) {
                ns = str;
                if (tmp == j) continue;
                ns[i] = j;
                for (int k = -1; k <= 1; k++) {
                    if (tmp == k || j == k) continue;
                    ns.insert(ns.begin() + i + 1, k);
                    
                    np = path;
                    string st = "2 ";
                    st.push_back(i + 1);
                    st.push_back(' ');
                    st += j;
                    st.push_back(' ');
                    st += k;
                    np.push_back(st);

                    q.push({cnt + 1, ns, np});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> s1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char in; cin >> in;
        if (in == 'R') s1.push_back(-1);
        if (in == 'G') s1.push_back(0);
        if (in == 'B') s1.push_back(1);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        char in; cin >> in;
        if (in == 'R') s2.push_back(-1);
        if (in == 'G') s2.push_back(0);
        if (in == 'B') s2.push_back(1);
    }

    for (int i = s2.size() - 1; i >= 0; i--) {
        s3.push_back(s2[i]);
    }

    vector<string> empty_v;
    bfs(0, s1, empty_v);
    if (ans.size() == 0) {
        cout << 0 << '\n';
        return 0;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i][0] == 1) cout << ans[i] << '\n';
        else {
            for (int j = 0; j < ans[i].size(); j++) {
                if (j == 4 || j == 6) {
                    if (ans[i][j] == -1) cout << 'R';
                    else if (ans[i][j] == 0) cout << 'G';
                    else if (ans[i][j] == 1) cout << 'B';
                }
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
}

// void recur(int cnt, vector<int> str, vector<string> path) {
//     //종료 조건
//     if (cnt >= 10004) return;
//     if (str == s2 || str == s3) {
//         ans = path;
//         return;
//     }
//     vector<int> ns;
//     vector<string> np;

//     //하나로 합치기
//     for (int i = 0; i < str.size() - 1; i++) {
//         ns = str;
//         int tmp = (str[i] + str[i + 1]) * (-1);
//         ns.erase(ns.begin() + i);
//         ns[i] = tmp;

//         np = path;
//         tmp = i + 1;
//         string st = "1 ";
//         st += to_string(tmp);
//         st.push_back(' ');
//         tmp++;
//         st += to_string(tmp);
//         np.push_back(st);

//         recur(cnt + 1, ns, np);
//     }

//     //둘로 쪼개기
//     for (int i = 0; i < str.size(); i++) {
//         int tmp = str[i];
//         for (int j = -1; j <= 1; j++) {
//             ns = str;
//             if (tmp == j) continue;
//             ns[i] = j;
//             for (int k = -1; k <= 1; k++) {
//                 if (tmp == k || j == k) continue;
//                 ns.insert(ns.begin() + i + 1, k);
                
//                 np = path;
//                 string st = "2 ";
//                 st.push_back(i + 1);
//                 st.push_back(' ');
//                 st += j;
//                 st.push_back(' ');
//                 st += k;
//                 np.push_back(st);

//                 recur(cnt + 1, ns, np);
//             }
//         }
//     }
    
//     ns.clear(); np.clear();
//     ns.shrink_to_fit(); np.shrink_to_fit();
// }