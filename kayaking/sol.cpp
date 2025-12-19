#include <bits/stdc++.h>
using namespace std;

static int n;
static vector<int> people;
static vector<bool> taken;
static array<int, 2> skips{-1, -1};
static int TAKE_MAX = -1;

int broken_solve(int n_skips = 0, int i = 0, int prev = -1)
{
    if (i == people.size() - 2)
        return 0;

    // skip
    int skip = TAKE_MAX;
    if (n_skips < 2) {
        skips.at(n_skips) = i;
        skip = min(skip, broken_solve(n_skips + 1, i + 1));
        skips.at(n_skips) = -1;
    }

    int take = TAKE_MAX;
    for (int j = 0; j < people.size(); ++j)
    {
        if (taken[j] || skips[0] == j || skips[1] == j)
            continue;

        taken[j] = true;
        take = min(
            take,
            prev == -1 ? broken_solve(n_skips, i + 1, j)
                       : abs(people[j] - people[prev]) + broken_solve(n_skips, i + 1, -1));
        taken[j] = false;
    }

    return min(skip, take);
}

int solve(void) {
    sort(begin(people), end(people));

    long long ans = accumulate(begin(people), end(people), 0);

    for (int i = 0; i < people.size(); ++i) {
        for (int j = i+1; j < people.size(); ++j) {
            long long local = 0;

            int person1 = 0;
            while (person1 < people.size()) {
                if (person1 == i || person1 == j) {
                    person1++; continue;
                };

                int person2;
                for (int l = person1+1; l < people.size(); ++l) {
                    if (l == i || l == j) continue;
                    person2 = l;
                    break;
                }

                local += abs(people[person1] - people[person2]);
                person1 = person2 + 1;
            }
            ans = min(ans, local);
        }
    }

    return ans;
}

int main(void)
{
    cin >> n;
    taken.resize(2 * n, false);
    people.resize(2 * n);

    for (int i = 0; i < 2*n; ++i) cin >> people[i];
    cout << solve() << endl;
}
