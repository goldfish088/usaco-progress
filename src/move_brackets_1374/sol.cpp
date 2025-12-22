#include <bits/stdc++.h>
using namespace std;

static inline void redirect_io(string basename);

int solve(string& s, int n) {
    vector<char> st;

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == '(') {
            st.push_back(c);
            continue;
        }

        // c is a close paren
        if (st.empty()) {
            ans++;
            continue;
        }

        st.pop_back();
    }

    return ans;
}

int main(void) {
    redirect_io(".");

    int t; cin >> t;
    vector<int> ans(t);
    for (int i = 0; i < t; ++i) {
        int n; cin >> n;
        string s; cin >> s;
        ans[i] = solve(s, n);
    }

    for (int i = 0; i < t; ++i) cout << ans[i] << endl;
}

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename) {
    if (!basename.compare(".")) return;
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}