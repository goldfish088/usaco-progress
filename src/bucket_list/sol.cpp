#include <bits/stdc++.h>
using namespace std;


#define IO_BASENAME "blist"
static void setio();

int main(void) {
    setio();

    // this is possible because all si's and fi's are unique
    // there will not be collisions
    map<size_t, size_t> action;

    size_t ncows; cin >> ncows;

    vector<int> pos(ncows*2);

    for (size_t i = 0; i < ncows; ++i) {
        int start; cin >> start;
        int end; cin >> end;

        int buckets; cin >> buckets;
        action[start] = -buckets;
        action[end] = buckets;
        pos[2*i] = start;
        pos[2*i+1] = end;
    }

    sort(begin(pos), end(pos));

    size_t remaining = 0;
    size_t needed = 0;

    for (auto& p : pos) {
        int offset = action[p];
        size_t mag = abs(offset);

        if (offset < 0) {
            if (remaining < mag) {
                needed += mag - remaining;
                remaining = 0;
            } else {
                remaining -= mag;
            }
        } else {
            remaining += offset;
        }
    }

    cout << needed << '\n';
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