#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Meerkat {
    int height;
    char direction;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<Meerkat> meerkats(N);

    for (int i = 0; i < N; i++) {
        cin >> meerkats[i].height >> meerkats[i].direction;
    }

    int max_count = 0;
    stack<int> left_stack, right_stack;

    // 왼쪽을 바라보는 미어캣 처리
    for (int i = N - 1; i >= 0; --i) {
        if (meerkats[i].direction == 'L') {
            while (!left_stack.empty() && left_stack.top() < meerkats[i].height) {
                left_stack.pop();
            }
            left_stack.push(meerkats[i].height);
            max_count++;
        }
    }

    // 오른쪽을 바라보는 미어캣 처리
    for (int i = 0; i < N; ++i) {
        if (meerkats[i].direction == 'R') {
            while (!right_stack.empty() && right_stack.top() < meerkats[i].height) {
                right_stack.pop();
            }
            right_stack.push(meerkats[i].height);
            max_count++;
        }
    }

    cout << max_count << '\n';

    return 0;
}
