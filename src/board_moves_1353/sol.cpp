#include <bits/stdc++.h>
using namespace std;

static inline void redirect_io(string basename);

constexpr auto MAX_N = (5 * 100000LL - 1);
constexpr auto MAX_DP = (MAX_N + 1) / 2;

static vector<long long> dp(MAX_DP, 0);

int main(void) {
    redirect_io(".");

    dp[0] = 0;
    long long sq = 0;
    for (auto i = 1LL; i < MAX_DP; ++i) {
        sq += 2*i - 1;
        dp[i] = 8*sq + dp[i-1];
    }

    int t; cin >> t;
    vector<long long> ans(t);
    for (auto& _case : ans) {
        int k; cin >> k;
        int j = (k-1)/2;
        _case = dp[j];
    }

    for (auto& _case : ans) {
        cout << _case << endl;
    }
}

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename) {
    if (!basename.compare(".")) return;
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}