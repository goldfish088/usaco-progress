#include <bits/stdc++.h>
using namespace std;

#define MAX_SESSIONS 10
#define MAX_COWS 20

int main(void) {
    // freopen("gymnastics.in", "r", stdin);
    // freopen("gymnastics.out", "w", stdout);

    int n_sessions, n_cows;
    cin >> n_sessions >> n_cows;

    int perf[MAX_SESSIONS][MAX_COWS];

    for (int session = 0; session < n_sessions; ++session) {
        for (int cow = 0; cow < n_cows; ++cow) {
            int cow_number;
            cin >> cow_number;
            perf[session][cow_number-1] = cow+1;
        }
    }

    int ans = 0;

    for (int cow = 0; cow < n_cows; ++cow) {
        for (int other = 0; other < n_cows; ++other) {
            if (other == cow) continue;

            bool consistent = true;
            for (int session = 0; session < n_sessions; ++session) {
                if (perf[session][cow] > perf[session][other]) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
