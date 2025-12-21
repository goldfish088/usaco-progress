#include <bits/stdc++.h>
using namespace std;

static inline void redirect_io(string basename);

int main(void)
{
    redirect_io(".");

    uint32_t distinct = {};
    string s; cin >> s;

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        distinct |= 1u << (s[i] - 'a');
    }

    int cnt = 0;
    while (distinct != 0) {
        cnt += (distinct & 1);
        distinct >>= 1;
    }

    if (cnt & 1) {
        cout << "IGNORE HIM!" << endl;
    } else {
        cout << "CHAT WITH HER!" << endl;
    }

}

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename)
{
    if (!basename.compare("."))
        return;
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}