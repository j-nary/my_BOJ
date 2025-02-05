#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> plusOneSecond(int h, int m, int s) {
    s++;
    if (s == 60) { m++; s = 0; }
    if (m == 60) { h++; m = 0; }

    vector<int> res = {h, m, s};
    return res;
}

int timeToSecond(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int isDang(int ph, int pm, int ps, int nh, int nm, int ns) {
    double phSpec = (ph & 12) * 30.0 + pm * 0.5 + ps * (1 / 120.0);
    double pmSpec = pm * 6.0 + ps * 0.1;
    double psSpec = ps * 6.0;

    double nhSpec = (nh & 12) * 30.0 + nm * 0.5 + ns * (1 / 120.0);
    double nmSpec = nm * 6.0 + ns * 0.1;
    double nsSpec = ns * 6.0;

    int ret = 0;
    if (psSpec <= phSpec && nhSpec < psSpec) ret++;
    if (psSpec <= pmSpec && nmSpec < nsSpec) ret++;
    if (phSpec == pmSpec) ret--;
    return ret;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    int h3, m3, s3;
    while(1) {
        vector<int> nxtTime = plusOneSecond(h1, m1, s1);
        h3 = nxtTime[0], m3 = nxtTime[1], s3 = nxtTime[2];
        if (timeToSecond(h3, m3, s3) > timeToSecond(h2, m2, s2)) break;
        answer += isDang(h1, m1, s1, h3, m3, s3);
        h1 = h3; m1 = m3; s1 = s3;
    }
    answer += isDang(h2, m2, s2, h2, m2, s2);

    return answer;
}

int main() {
//   cout << solution(0, 5, 30, 0, 7, 0) << '\n';
//   cout << solution(12, 0, 0, 12, 0, 30) << '\n';
//   cout << solution(0, 6, 1, 0, 6, 6) << '\n';
//   cout << solution(11, 59, 30, 12, 0, 0) << '\n';
//   cout << solution(11, 58, 59, 11, 59, 0) << '\n';
  cout << solution(1, 5, 5, 1, 5, 6) << '\n';
//   cout << solution(0, 0, 0, 23, 59, 59) << '\n';
}