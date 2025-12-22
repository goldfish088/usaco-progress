#include <bits/stdc++.h>
using namespace std;


// #define IO_BASENAME "TODO"
static void setio();

int main(void) {
    setio();

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> types(n+1);
    for (int i = 0; i < n; ++i) cin >> types[i+1];

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;

        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    vector<int> dist(n+1, -1);
    int start = 1;
    dist[start] = 0;

    deque<int> q;
    q.push_back(start);

    while (!q.empty()) {
        int curr = q.front(); q.pop_front();

        for (auto& neigh : adj[curr]) {
            if (dist[neigh] == -1) {
                dist[neigh] = 1 + dist[curr];
                q.push_back(neigh);
            }
        }
    }

    vector<int> tdist(k+1, -1);
    for (int i = 1; i <= n; ++i) {
        int t = types[i];
        int d = dist[i];
        tdist[t] = max(tdist[t], d);
    }

    for (auto it = tdist.begin()+1; it != tdist.end(); ++it) {
        cout << *it << ' ';
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