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

bool isDang(int h, int m, int s) {
    double hSpec = h / 12.0;
    double mSpec = m / 60.0;
    double sSpec = s / 60.0;

    return hSpec == sSpec || mSpec == sSpec;
}
int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    while(1) {
        if (timeToSecond(h1, m1, s1) > timeToSecond(h2, m2, s2)) break;

        if (isDang(h1, m1, s1)) answer++;

        vector<int> nxtTime = plusOneSecond(h1, m1, s1);
        h1 = nxtTime[0], m1 = nxtTime[1], s1 = nxtTime[2];
    }
    return answer;
}

int main() {
  cout << solution(0, 6, 1, 0, 6, 6) << '\n';
}