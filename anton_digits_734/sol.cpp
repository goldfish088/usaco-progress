#include <bits/stdc++.h>
using namespace std;

static inline void redirect_io(string basename);

int main(void) {
    redirect_io(".");

    /*
    digits[0] -> '2'
    digits[1] -> '3'
    digits[2] -> '5'
    digits[3] -> '6'
    */
    array<int, 4> digits;
    for (auto& d : digits) cin >> d;

    // compute # 256's
    long long ans = 0;

    auto vm = min({digits[0], digits[2], digits[3]});
    ans += vm * 256;
    digits[0] -= vm;
    digits[2] -= vm;
    digits[3] -= vm;

    vm = min({digits[0], digits[1]});
    ans += vm * 32;
    digits[0] -= vm;

    cout << ans << endl;
}

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename) {
    if (!basename.compare(".")) return;
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}