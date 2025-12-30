#include <bits/stdc++.h>
using namespace std;


// #define IO_BASENAME "TODO"
static void setio();

int main(void) {
    setio();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> seen;

        int odd = 0;
        int even = 0;

        for (int i = 0; i < n; ++i) {
            int k; cin >> k;
            seen.insert(k);
            if (k & 1) {
                odd++;
            } else {
                even++;
            }
        }

        if (odd % 2 != even % 2) {
            cout << "NO\n";
            break;
        }

        if (odd % 2 == 0) {
            cout << "YES\n";
            break;
        }

        for (auto it = seen.begin(); it != seen.end(); ++it) {
            auto fst_val = *it;

            advance(it, 1);
            if (it == seen.end()) break;

            auto snd_val = *it;
            if (abs(snd_val - fst_val) == 1) {
                cout << "YES\n";
                break;
            }
        }
    }
}

static inline void setio(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef IO_BASENAME
        string name = IO_BASENAME;
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}