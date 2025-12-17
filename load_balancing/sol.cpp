#include <bits/stdc++.h>
using namespace std;

int main(void) {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    // 1 <= n_cows <= 1e2
    int n_cows;
    cin >> n_cows;

    // 1 <= max_comp_val <= 1e6
    int max_comp_val;
    cin >> max_comp_val;

    // x, y
    vector<pair<int, int>> pos(n_cows);
    set<int> fence_x;
    set<int> fence_y;

    for (int i = 0; i < n_cows; ++i)
    {
        cin >> pos[i].first >> pos[i].second;
        fence_x.insert(pos[i].first+1);
        fence_y.insert(pos[i].second+1);
    }

    int m = n_cows;
    array<int, 4> quadrant;

    for (auto x : fence_x) {
        for (auto y : fence_y) {
            for (int i = 0; i < 4; ++i) quadrant[i] = 0;

            for (auto &[cow_x, cow_y] : pos) {
                if ((cow_x < x) && (cow_y > y)) {
                    quadrant[0]++;
                } else if ((cow_x > x) && (cow_y > y)) {
                    quadrant[1]++;
                } else if ((cow_x < x) && (cow_y < y)) {
                    quadrant[2]++;
                } else {
                    quadrant[3]++;
                }
            }
            m = min(m, *max_element(begin(quadrant), end(quadrant)));
        }
    }

    cout << m << endl;
}
