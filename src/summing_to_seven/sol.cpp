#include <bits/stdc++.h>
using namespace std;


#define IO_BASENAME "div7"
static void setio();

int main(void) {
    setio();

    int n; cin >> n;


    vector<int> prefix(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        prefix[i+1] = (k + prefix[i]) % 7;
    }

    int ans = 0;
    map<int, int> seen;
    seen[0] = 0;
    for (int i = 1; i < n+1; ++i) {
        if (seen.find(prefix[i]) != seen.end()) {
            ans = max(ans, i - seen[prefix[i]]);
        } else {
            seen[prefix[i]] = i;
        }
    }

    cout << ans << '\n';
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