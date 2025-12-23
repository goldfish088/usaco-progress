#include <bits/stdc++.h>
using namespace std;


// #define IO_BASENAME "TODO"
static void setio();

long long solution_dp(int n) {
    array<long long, 3> dp;
    dp[0] = 2;
    dp[1] = 6;

    for (int i = 2; i < n; ++i) {
        auto exact = dp[1] - dp[0];
        auto to_add = 2*exact;
        dp[2] = dp[1] + to_add;

        dp[0] = dp[1];
        dp[1] = dp[2];
    }

    return dp[min(n-1, 2)];
}

inline long long solution_math(int n) {
    // sum 2^i = 2*(2^n - 1)
    return 2*((1LL << n) - 1);
}

int main(void) {
    setio();
    int n; cin >> n;

    cout << solution_dp(n) << '\n';
    // cout << solution_math(n) << '\n';
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