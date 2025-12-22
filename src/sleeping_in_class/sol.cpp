#include <bits/stdc++.h>
using namespace std;

int solve_case(vector<int>& a, int remaining) {
    // base case
    if (remaining == 1) {
        return 0;
    }

    auto first_elem_it = find_if(begin(a), end(a), [](int num) { return num != -1; });

    int elem = *first_elem_it;

    // we have got all numbers matching (excluding the sentinel values)
    if (all_of(begin(a), end(a), [elem](int num) { return num == -1 || num == elem; })) {
        return 0;
    }

    int ans = remaining;
    for (int i = 0; i < a.size()-1; ++i) {
        if (a[i] == -1) continue;

        // attempt to combine i with i+1
        int old_ai = a[i];
        a[i+1] += old_ai;
        a[i] = -1;

        ans = min(ans, 1 + solve_case(a, remaining-1));
        a[i] = old_ai;
        a[i+1] -= old_ai;
    }

    return ans;
}

int solve_case(vector<int>& a) {
    int sum_a = accumulate(begin(a), end(a), 0);

    for (int num_ops = 0; num_ops < a.size()-1; ++num_ops) {
        int n_buckets = a.size() - num_ops;
        if ((sum_a % n_buckets) != 0) {
            n_buckets--;
            continue;
        }

        int avg = sum_a / n_buckets;
        int cur_sum = 0;
    
        bool possible = true;
        for (int i = 0; i < a.size() && possible; ++i) {
            cur_sum += a[i];

            if (cur_sum == avg) {
                cur_sum = 0;
            } else if (cur_sum > avg) {
                possible = false;
            }
        }

        if (possible) {
            return num_ops;
        };
    }

    return a.size() - 1;
}

int main(void) {
    int t; cin >> t;

    vector<int> ans(t);

    for (int i = 0; i < t; ++i) {
        int n; cin >> n;

        vector<int> a(n);
        for (int j = 0; j < n; ++j) cin >> a[j];

        ans[i] = solve_case(a);
    }

    for (auto modifications : ans) {
        cout << modifications << endl;
    }
}
