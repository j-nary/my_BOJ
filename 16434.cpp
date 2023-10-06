//BOJ_16434 드래곤 앤 던전 [골드4]
//시간초과
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct info {
    int t, a, h;
};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, ATK; cin >> N >> ATK; //초기 공격력
    vector<info> v;
    long long left = 1, right = 1e18;
    for (int i = 0; i < N; i++) {
        int t, a, h;
        //t==1; 몬스터 공격력, 몬스터 생명력
        //t==2; 증가할 공격력, 회복할 생명력
        cin >> t >> a >> h;
        v.push_back({t, a, h});
    }

    long long ans = 1e18;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long at = ATK;   //공격력
        long long hp = mid;   //생명력
        long long m_at = 0, m_hp = 0;     //몬스터의 공격력, 생명력
        bool die = false;
        for (int i = 0; i < N; i++) {
            if (v[i].t == 1) {
                m_at = v[i].a;
                m_hp = v[i].h;
                while(m_hp > 0) {
                    m_hp -= at;    //용사 공격
                    if (m_hp <= 0) break;
                    hp -= m_at;    //몬스터 공격
                    if (hp <= 0) {
                        die = true;
                        break;
                    }
                }
                if (die) break;
            } else {
                at += v[i].a;
                hp += v[i].h;
                if (hp > mid) hp = mid;
            }
        }

        if (die) {
            left = mid + 1;
        } else {
            right = mid - 1;
            ans = min(ans, mid);
        }
    }

    cout << ans << '\n';
}