#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, D;
        cin >> N >> D;

        vector<int> strawberries(N);
        for (int i = 0; i < N; i++) {
            cin >> strawberries[i];
        }

        sort(strawberries.begin(), strawberries.end());

        int maxStrawberries = 1;
        for (int i = 1; i < N; i++) {
            int dist = strawberries[i] - strawberries[i - 1];
            maxStrawberries = max(maxStrawberries, min(dist, D) / dist);
        }

        cout << "Case #" << tc << endl;
        cout << maxStrawberries << endl;
    }

    return 0;
}
