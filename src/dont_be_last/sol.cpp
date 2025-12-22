#include <bits/stdc++.h>
using namespace std;

static auto names = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename) {
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}

int main(void) {
    redirect_io("notlast");

    int num_entries; cin >> num_entries;

    map<string, int> total;
    for (auto name : names) total[name] = 0;


    for (int i = 0; i < num_entries; ++i) {
        string s; cin >> s;
        int qty; cin >> qty;
        total[s] += qty;
    }

    vector<pair<int, string>> cows;
    for (auto &[s, qty] : total) {
        cows.push_back(make_pair(qty, s));
    }

    sort(begin(cows), end(cows));

    auto first = cows[0].first;
    if (all_of(begin(cows)+1, end(cows), [first](auto c) { return c.first == first; })) {
        cout << "Tie" << endl;
        return 0;
    }

    size_t i = 0;
    while (cows[i].first == first && i < cows.size()) i++;

    if (i == cows.size() || (i < cows.size()-1 && cows[i+1].first == cows[i].first)) {
        cout << "Tie" << endl;
        return 0;
    }

    cout << cows[i].second << endl;
}
