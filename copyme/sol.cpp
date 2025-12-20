#include <bits/stdc++.h>
using namespace std;

static inline void redirect_io(string basename);

int main(void) {
    redirect_io("TODO");

    
}

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename) {
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}