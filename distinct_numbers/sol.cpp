#include <bits/stdc++.h>
using namespace std;

int main(void) {

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    sort(begin(nums), end(nums));

    int count = 1;
    int prev = nums[0];

    for (int i = 0; i < n; ++i) {
        if (nums[i] != prev) {
            count++;
            prev = nums[i];
        }
    }

    cout << count << endl;
}
