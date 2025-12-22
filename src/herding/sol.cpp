#include <bits/stdc++.h>
using namespace std;

static inline void redirect_io(string basename);

void triple_sort(int& a, int& b, int& c) {
    int total = a + b + c;
    int mn = min({a, b, c});
    int mx = max({a, b, c});
    int middle = total - mn - mx;

    a = mn;
    b = middle;
    c = mx;
}

int find_min(int one, int two, int three) {
    int d1 = two - one;
    int d2 = three - two;
    if (d1 == d2) {
        if (d1 == 1) return 0;
        if (d1 == 2) return 1;

        return 2;
    }

    if (d1 == 2 || d2 == 2) return 1;
    if (d1 == 1 || d2 == 1) return 2;

    return 2;
}

int find_max(int one, int two, int three) {
    int d1 = two - one;
    int d2 = three - two;
    return max(d1, d2) - 1;
}

int main(void) {
    redirect_io("herding");

    int one, two, three;
    cin >> one >> two >> three;
    triple_sort(one, two, three);
    cout << find_min(one, two, three) << '\n' << find_max(one, two, three) << endl;
}

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename) {
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}