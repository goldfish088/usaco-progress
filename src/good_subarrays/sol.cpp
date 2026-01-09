#include <bits/stdc++.h>
using namespace std;


// #define IO_BASENAME "TODO"
static void setio();

int main(void) {
    setio();
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string num; cin >> num;

        map<int, int> seen;
        seen[0] = 1;

        int cursum = 0;
        long long ans = 0;

        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; ++i) {
            cursum += num[i] - '0';
            prefix[i+1] = i+1 - cursum;

            ans += seen[prefix[i+1]]++;
        }

        cout << ans << '\n';
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