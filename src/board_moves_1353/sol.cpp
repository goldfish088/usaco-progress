#include <bits/stdc++.h>
using namespace std;

static void setio();

// #define IO_BASENAME "TODO"

constexpr auto MAX_N = (5 * 100000LL - 1);
constexpr auto MAX_DP = (MAX_N + 1) / 2;

static vector<long long> dp(MAX_DP, 0);

int main(void) {
    setio();

    dp[0] = 0;
    long long sq = 0;
    for (auto i = 1LL; i < MAX_DP; ++i) {
        sq += 2*i - 1;
        dp[i] = 8*sq + dp[i-1];
    }

    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        int j = (k-1)/2;
        cout << dp[j] << '\n';
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