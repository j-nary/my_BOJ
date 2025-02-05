#include <bits/stdc++.h>
#include <iostream>

using namespace std;

pair<int, int> splitTimeString(string time) {
    string hourStr = time.substr(0, 2);
    string minuteStr = time.substr(3, 2);
    
    int hour = stoi(hourStr);
    int minute = stoi(minuteStr);

    return {hour, minute};
}

string timeToString(pair<int, int> time) {
    string hour = to_string(time.first), minute = to_string(time.second);
    if (hour.length() < 2) hour = "0" + hour;
    if (minute.length() < 2) minute = "0" + minute;

    return hour + ":" + minute;
}

string actPrev(string pos) {
    pair<int, int> time = splitTimeString(pos);
    time.second -= 10;

    if (time.second < 0) {
        time.first--;
        time.second += 60;
    }

    if (time.first < 0) time = {0, 0};

    return timeToString(time);
}

string actNext(string pos, string video_len) {
    pair<int, int> time = splitTimeString(pos);
    time.second += 10;

    if (time.second > 60) {
        time.first++;
        time.second -= 60;
    }
    
    return min(video_len, timeToString(time));
}

string skipOpening(string pos, string op_start, string op_end) {
    if (op_start <= pos && pos <= op_end) return op_end;
    return pos;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    for (string command: commands) {
        pos = skipOpening(pos, op_start, op_end);
        if (command == "next") pos = actNext(pos, video_len);
        else if (command == "prev") pos = actPrev(pos);
    }
    pos = skipOpening(pos, op_start, op_end);

    return pos;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cout << solution("34:33", "13:00", "00:55", "02:55", {"next", "prev"}) << '\n';
  cout << solution("10:55", "00:05", "00:15", "06:55", {"prev", "next", "next"}) << '\n';
  cout << solution("07:22", "04:05", "00:15", "04:07", {"next"}) << '\n';
}