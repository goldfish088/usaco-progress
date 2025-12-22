#include <bits/stdc++.h>
using namespace std;


// #define IO_BASENAME "TODO"
static void setio();

int main(void) {
    setio();

    int n;
    cin >> n;

    vector<int> fst, snd;

    map<int, int> freq;
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;

        int cnt = ++freq[num];

        if (cnt == 1) {
            fst.push_back(num);
        } else if (cnt == 2) {
            snd.push_back(num);
        } else {
            possible = false;
        }
    }

    if (!possible) {
        cout << "NO" << '\n';
        return 0;
    }

    sort(begin(fst), end(fst));
    sort(rbegin(snd), rend(snd));

    cout << "YES" << '\n';

    cout << fst.size() << '\n';
    for (size_t i = 0; i < fst.size(); ++i) {
        cout << fst[i] << ' ';
    }
    cout << '\n';

    cout << snd.size() << '\n';
    for (size_t i = 0; i < snd.size(); ++i) {
        cout << snd[i] << ' ';
    }
    cout << '\n';
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