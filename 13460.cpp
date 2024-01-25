//BOJ_13459 구슬 탈출 2 [골드 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

char M[12][12];
set<pair<int, int>> chk[12][12];

pair<int, int> H;   //구멍의 위치
struct node {
    int r, c;
    int dir;    //0 동, 1 서, 2 남, 3 북으로 기울였을 때
};
vector<node> promising;
struct node2 {
    int Rr, Rc;
    int Br, Bc;
    int depth, dir;
};
void fillPromising() {
    int r = H.first;
    int c = H.second;

    // 동쪽으로 기울일 경우
    while(1) {
        c--;
        if (M[r][c] == '#') break;
        promising.push_back({r, c, 0});
    }
    c = H.second;
    // 서쪽으로 기울일 경우
    while(1) {
        c++;
        if (M[r][c] == '#') break;
        promising.push_back({r, c, 1});
    }
    c = H.second;
    // 남쪽으로 기울일 경우
    while(1) {
        r--;
        if (M[r][c] == '#') break;
        promising.push_back({r, c, 2});
    }
    r = H.first;
    // 북쪽으로 기울일 경우
    while(1) {
        r++;
        if (M[r][c] == '#') break;
        promising.push_back({r, c, 3});
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, m;
    cin >> N >> m;

    pair<int, int> R;
    pair<int, int> B;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> M[i][j];
            if (M[i][j] == 'O') H = {i, j};
            else if (M[i][j] == 'R') R = {i, j};
            else if (M[i][j] == 'B') B = {i, j};
        }
    }
    fillPromising();  // 구멍의 위치에 도달 가능한 경우의 수 채우기

    queue<node2> q;
    int ans = 100;
    q.push({R.first, R.second, B.first, B.second, 0, -1});
    chk[R.first][R.second].insert({B.first, B.second});
    while (!q.empty()) {
        int Rr = q.front().Rr;
        int Rc = q.front().Rc;
        int Br = q.front().Br;
        int Bc = q.front().Bc;
        int d = q.front().depth;
        int dir = q.front().dir;
        q.pop();

        if (d == 10 || ans < d) continue;
        int dpsb = (1 << 4) - 1;
        for (int i = 0; i < promising.size(); i++) {
            if (Br == promising[i].r && Bc == promising[i].c) {
                dpsb &= ~(1 << promising[i].dir);
            }
        }
        
        for (int i = 0; i < promising.size(); i++) {
            if (Rr == promising[i].r && Rc == promising[i].c && dpsb & (1 << promising[i].dir)) {
                ans = min(ans, d + 1);
            }
        }

        int NRr = Rr, NRc = Rc, NBr = Br, NBc = Bc;
        bool Rflag = true, Bflag = true;
        if (dir != 0 && dpsb & (1 << 0)) {      // 동쪽으로 기울이기
            while (Rflag || Bflag) {
                if (M[Rr][NRc + 1] == '#') Rflag = false;
                if (Rflag) NRc++;
                if (M[Br][NBc + 1] == '#') {
                    if (NRc == NBc && Rr == Br) {
                        NRc--;
                        Rflag = false;
                    }
                    Bflag = false;
                }
                if (!Rflag && (NBc + 1 == NRc && Br == Rr)) Bflag = false;
                if (Bflag) NBc++;
            }
            if (chk[Rr][NRc].find({Br, NBc}) == chk[Rr][NRc].end()) {
                q.push({Rr, NRc, Br, NBc, d + 1, 0});
                chk[Rr][NRc].insert({Br, NBc});
            }
            NRc = Rc;
            NBc = Bc;
        }
        Rflag = true; Bflag = true;
        if (dir != 1 && dpsb & (1 << 1)) {      // 서쪽으로 기울이기
            while (Rflag || Bflag) {
                if (M[Rr][NRc - 1] == '#') Rflag = false;
                // if (!Bflag && (NRc - 1 == NBc && Rr == Br)) Rflag = false;
                if (Rflag) NRc--;
                if (M[Br][NBc - 1] == '#') {
                    if (NRc == NBc && Rr == Br) {
                        NRc++;
                        Rflag = false;
                    }      
                    Bflag = false;
                }
                if (!Rflag && (NBc - 1 == NRc && Br == Rr)) Bflag = false;
                if (Bflag) NBc--;
            }
            if (chk[Rr][NRc].find({Br, NBc}) == chk[Rr][NRc].end()) {
                q.push({Rr, NRc, Br, NBc, d + 1, 1});
                chk[Rr][NRc].insert({Br, NBc});
            }
            NRc = Rc;
            NBc = Bc;
        }
        Rflag = true; Bflag = true;
        if (dir != 2 && dpsb & (1 << 2)) {      // 남쪽으로 기울이기
            while (Rflag || Bflag) {
                if (M[NRr + 1][Rc] == '#') Rflag = false;
                // if (!Bflag && (NRr + 1 == NBr && Rc == Bc)) Rflag = false;
                if (Rflag) NRr++;
                if (M[NBr + 1][Bc] == '#') {
                    if (NRr == NBr && Rc == Bc) {
                        NRr--;
                        Rflag = false;
                    }      
                    Bflag = false;
                }
                if (!Rflag && (NBr + 1 == NRr && Bc == Rc)) Bflag = false;
                if (Bflag) NBr++;
            }
            if (chk[NRr][Rc].find({NBr, Bc}) == chk[NRr][Rc].end()) {
                q.push({NRr, Rc, NBr, Bc, d + 1, 2});
                chk[NRr][Rc].insert({NBr, Bc});
            }
            NRr = Rr;
            NBr = Br;
        }
        Rflag = true; Bflag = true;
        if (dir != 3 && dpsb & (1 << 3)) {      // 북쪽으로 기울이기
            while (Rflag || Bflag) {
                if (M[NRr - 1][Rc] == '#') Rflag = false;
                // if (!Bflag && (NRr - 1 == NBr && Rc == Bc)) Rflag = false;
                if (Rflag) NRr--;
                if (M[NBr - 1][Bc] == '#') {
                    if (NRr == NBr && Rc == Bc) {
                        NRr++;
                        Rflag = false;
                    }      
                    Bflag = false;
                }
                if (!Rflag && (NBr - 1 == NRr && Bc == Rc)) Bflag = false;
                if (Bflag) NBr--;
            }
            if (chk[NRr][Rc].find({NBr, Bc}) == chk[NRr][Rc].end()) {
                q.push({NRr, Rc, NBr, Bc, d + 1, 3});
                chk[NRr][Rc].insert({NBr, Bc});
            }
            NRr = Rr;
            NBr = Br;
        }
    }

    if (ans == 100) cout << -1 << '\n';
    else cout << ans << '\n';
}