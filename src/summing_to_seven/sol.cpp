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
    array<int, 7> mod_seen{};

    for (int i = 1; i < n+1; ++i) {
        // 0 is sentinel, since we are using 1-indexing
        if (mod_seen[prefix[i]] != 0) {
            ans = max(ans, i - mod_seen[prefix[i]]);
        } else {
            mod_seen[prefix[i]] = i;
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