#include <bits/stdc++.h>
using namespace std;

static inline void redirect_io(string basename);

int main(void)
{
    redirect_io("paint");

    int fj_start, fj_end;
    cin >> fj_start >> fj_end;
    if (fj_start > fj_end) swap(fj_start, fj_end);

    int b_start, b_end;
    cin >> b_start >> b_end;
    if (b_start > b_end) swap(b_start, b_end);

    int start, end;

    if (fj_start <= b_start && b_start <= fj_end) {
        start = fj_start;
        end = max(b_end, fj_end);
    } else if (fj_start <= b_end && b_end <= fj_end) {
        start = min(b_start, fj_start);
        end = fj_end;
    } else if ((fj_start < b_start && b_end < fj_end) || (b_start < fj_start && fj_end < b_end)) {
        start = min(b_start, fj_start);
        end = max(b_end, fj_end);
    } else {
        start = 0;
        end = (fj_end - fj_start) + (b_end - b_start);
    }

    cout << end - start << endl;
}

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename)
{
    if (!basename.compare("."))
        return;
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}