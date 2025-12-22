#include <bits/stdc++.h>
using namespace std;

using chars = vector<char>;

bool has_intersection(chars& s1, chars& s2, int n) {
    assert(s1.size() == s2.size());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s1[i] == s2[j]) return true;
        }
    }

    return false;
}

int main(void) {

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);


    int rows, genome_len;
    cin >> rows >> genome_len;

    vector<string> spotty(rows);
    vector<string> plain(rows);

    for (int i =0; i < rows; ++i) cin >> spotty[i];
    for (int i =0; i < rows; ++i) cin >> plain[i];

    chars spotty_chars(rows);
    chars plain_chars(rows);

    int ans = 0;
    for (int i = 0; i < genome_len; ++i) {
        for (int cow = 0; cow < rows; ++cow) {
            spotty_chars[cow] = spotty[cow][i];
            plain_chars[cow] = plain[cow][i];
        }

        ans += !has_intersection(spotty_chars, plain_chars, rows);
    }

    cout << ans << endl;
}
