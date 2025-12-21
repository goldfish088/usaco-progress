#include <bits/stdc++.h>
using namespace std;

static inline void redirect_io(string basename);


// 9 3 15 20

int solve(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    vector<int> nums_copy = nums;
    sort(nums_copy.begin(), nums_copy.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += nums[i] != nums_copy[i];
    }

    return max(0, --ans);
}

int main(void) {
    // redirect_io(".");
    redirect_io("outofplace");
    
    // 2 4 7 7 9 3

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)  cin >> nums[i];

    int ans = solve(nums);
    cout << ans << endl;
}

static string suffix_in = ".in";
static string suffix_out = ".out";

static inline void redirect_io(string basename) {
    if (!basename.compare(".")) return;
    freopen((basename + suffix_in).c_str(), "r", stdin);
    freopen((basename + suffix_out).c_str(), "w", stdout);
}