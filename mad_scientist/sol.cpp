#include <bits/stdc++.h>
using namespace std;

static inline void redirect_io(string basename);

int greedy(string& a, string& b) {
    int ans = 0;
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n; ++i) {
        bool set = false;
        while (a[i] != b[i]) {
            set = true;
            i++;
        }

        ans += static_cast<int>(set);
    }
    return ans;
}

int main(void) {
    auto name = "breedflip";
    redirect_io(name);

    int n; cin >> n;
    string a, b;
    cin >> a >> b;

    cout << greedy(a, b) << endl;
}

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename) {
    if (!basename.compare(".")) return;
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}