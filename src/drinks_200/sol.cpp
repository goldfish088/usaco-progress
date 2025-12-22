#include <bits/stdc++.h>
using namespace std;

static inline void redirect_io(string basename);

int main(void) {
    redirect_io(".");

    int n; cin >> n;

    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        ans += k;
    }

    cout << ans / n << endl;
}

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename) {
    if (!basename.compare(".")) return;
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}