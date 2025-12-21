#include <bits/stdc++.h>
using namespace std;

static inline void redirect_io(string basename);

int main(void) {
    redirect_io(".");

    set<int> nums;
    for (int i = 0; i < 4; ++i) {
        int k; cin >> k;
        nums.insert(k);
    }

    cout << 4 - nums.size() << endl;
}

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename) {
    if (!basename.compare(".")) return;
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}