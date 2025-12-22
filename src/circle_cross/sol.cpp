#include <bits/stdc++.h>
using namespace std;


int main(void) {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string s; cin >> s;

    int ans = 0;

    vector<int> start(26, -1), finish(26, -1);
    for (int i = 0; i < s.size(); ++i) {
        if (start[s[i] - 'A'] == -1) {
            start[s[i] - 'A'] = i;
        } else {
            finish[s[i] - 'A'] = i;
        }
    }

    // we literally do not care about `s` anymore, we have encoded it into `start`
    // and `finish` already
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (start[i] < start[j] && start[j] < finish[i] && finish[i] < finish[j]) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
