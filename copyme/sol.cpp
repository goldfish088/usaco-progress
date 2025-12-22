#include <bits/stdc++.h>
using namespace std;


// #define IO_BASENAME "TODO"
static void setio();

int main(void) {
    setio();

    
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