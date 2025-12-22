#include <bits/stdc++.h>
using namespace std;

int solve(int n, string& s) {
    /* first check if the entire string is unique */
    int freq[26] = {0};
    for (int i = 0; i < 26; ++i) assert(freq[i] == 0);

    bool single = true;
    for (int i = 0; single && i < n; ++i) {
        if (freq[s[i] - 'A']++) {
            single = false;
        }
    }
    if (single) return 0;

    int l = 1;
    int r = n-1;
    int prev = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        set<string> seen;

        bool found = true;

        for (int start = 0; start <= n - mid; ++start) {
            string substr;
            for (int i = start; i < start + mid; ++i) {
                substr.push_back(s[i]);
            }

            if (seen.find(substr) != seen.end()) {
                found = false;
                break;
            }

            seen.insert(substr);
        }

        if (found) {
            prev = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return prev;
}

int main(void) {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n; cin >> n;
    string s; cin >> s;
    cout << solve(n, s) << endl;
}
