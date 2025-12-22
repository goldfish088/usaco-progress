#include <bits/stdc++.h>
using namespace std;

int main(void) {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;

    int x_lim = (m / x) + 1;
    int y_lim = (m / y) + 1;

    int ans = 0;
    for (int i = 0; i < x_lim; ++i) {
        for (int j = 0; j < y_lim; ++j) {
            int linear_comb = i*x + j*y;
            if (linear_comb <= m) {
                ans = max(ans, i*x + j*y);
            }
        }
    }

    cout << ans << endl;
}
