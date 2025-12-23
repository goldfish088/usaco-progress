#include <bits/stdc++.h>
using namespace std;


// #define IO_BASENAME "TODO"
static void setio();

using mut_string = string&;

bool next_permutation(mut_string curr, vector<string>& all) {
    // find the position of the pivot point
    int suffix_start = -1;
    for (size_t i = curr.size()-1; i > 0; i--) {
        if (curr[i] >= curr[i-1]) {
            suffix_start = i;
            break;
        }
    }

    if (suffix_start == -1) return false;

    auto to_swap = suffix_start-1;
    auto swap_with = -1;
    for (size_t i = curr.size()-1; i > 0; --i) {
        if (curr.at(i) > curr.at(to_swap)) {
            swap_with = i;
            break;
        }
    }

    assert(swap_with != -1);
    swap(curr[to_swap], curr[swap_with]);
    reverse(begin(curr)+suffix_start, end(curr));
    all.push_back(curr);

    return true;
}

array<string, 3> to_permute = {"12", "123", "1234"};
array<vector<string>, 3> all;

void all_permutations(void) {
    for (size_t i = 0; i < to_permute.size(); ++i) {
        string curr = to_permute[i];

        // may have needed to sort curr
        all[i].push_back(curr);
        while (next_permutation(curr, all[i]));
    }
}


// O(n) space, where n == actual.size() == expected.size()

void solve(string& actual, string& expected) {
    int a = 0;
    int b = 0;

    int n = static_cast<int>(actual.size());
    vector<int> prev(n, -1);

    for (int i = 0; i < n; ++i) {
        int actual_digit = actual[i] - '0';
        int expected_digit = expected[i] - '0';

        if (actual[i] == expected[i]) {
            a++;
        } else {
            if (prev[actual_digit-1] == -1) {
                prev[actual_digit-1] = i;
            } else {
                b++;
            }

            if (prev[expected_digit-1] == -1) {
                prev[expected_digit-1] = i;
            } else {
                b++;
            }
        }
    }

    cout << a << 'A' << b << 'B' << '\n';
}

int main(void) {
    setio();

    all_permutations();
    int t; cin >> t;
    while (t--) {
        string s; int i, j;
        cin >> s >> i >> j;

        i--; j--;

        int permute_index = static_cast<int>(s.size()-2);
        auto actual = all[permute_index][i];
        auto expected = all[permute_index][j];

        solve(actual, expected);
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