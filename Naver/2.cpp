#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 15; // QR 코드 개수 제한
vector<vector<string>> qr_codes;
int n, qr_size;
vector<vector<int>> adj; // 유사도 판별을 위한 그래프 (인접 행렬)

90도 회전하는 함수랑 유사도 계산하는 함수 보여줄까?
// QR 코드 90도 회전 함수
vector<string> rotate90(const vector<string>& qr) {
    vector<string> rotated(qr_size, string(qr_size, ' '));
    for (int i = 0; i < qr_size; i++)
        for (int j = 0; j < qr_size; j++)
            rotated[j][qr_size - i - 1] = qr[i][j]; // 시계방향 90도 회전
    return rotated;
}

// 두 QR 코드 간 유사도 계산
double calculate_similarity(const vector<string>& qr1, const vector<string>& qr2) {
    int same = 0, total = qr_size * qr_size;
    for (int i = 0; i < qr_size; i++)
        for (int j = 0; j < qr_size; j++)
            if (qr1[i][j] == qr2[i][j]) same++;
    return ((double)same / total) * 100;
}

// 유사도가 50% 이상인지 검사
bool is_similar(const vector<string>& qr1, const vector<string>& qr2) {
    vector<string> rotated = qr2;
    for (int i = 0; i < 4; i++) { // 90도 회전 4번까지 검사
        if (calculate_similarity(qr1, rotated) > 50.0)
            return true;
        rotated = rotate90(rotated);
    }
    return false;
}

// 독립 집합 찾기 (비트마스크 백트래킹)
int max_qr_set(int idx, int used) {
    if (idx == n) return __builtin_popcount(used); // 사용된 QR 코드 개수 반환

    // 현재 QR 코드를 포함할 수 있는지 확인
    bool can_use = true;
    for (int i = 0; i < idx; i++) {
        if ((used & (1 << i)) && adj[i][idx]) {
            can_use = false;
            break;
        }
    }

    int res = max_qr_set(idx + 1, used); // 현재 QR 코드 사용 안 하는 경우
    if (can_use) res = max(res, max_qr_set(idx + 1, used | (1 << idx))); // 사용하는 경우

    return res;
}

vector<int> solution(int n, vector<vector<string>> qr) {
    qr_size = qr[0].size();
    // n은 qr 개수, qr_size는 qr 문자열 길이
    // n도 쓰여야돼 qr_size 변수 새로 만들엉 !
    

    adj.assign(n, vector<int>(n, 0));

    // QR 코드 간 유사도 비교 및 그래프 생성
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (is_similar(qr[i], qr[j])) {
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }

    // 독립 집합 찾기 (최대 개수 QR 선택)
    vector<int> answer;
    int max_set_size = max_qr_set(0, 0);

    // 선택된 QR 코드 찾기
    for (int i = 0; i < n; i++) {
        int mask = (1 << i);
        if (max_qr_set(i + 1, mask) == max_set_size) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main() {
    vector<vector<string>> qr = {
        {"##..", ".##.", "..##", "...."},
        {".##.", "..##", "....", "##.."},
        {"....", "....", "####", "####"},
        {"####", "####", "....", "...."},
        {".##.", "##..", "....", "..##"},
        {"....", "....", "####", "####"}
    };

    vector<int> result = solution(6, qr);
    cout << "동시에 사용할 수 있는 QR 코드: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}


1. rotate 4번 다 시켜서 similar 비교해야돼