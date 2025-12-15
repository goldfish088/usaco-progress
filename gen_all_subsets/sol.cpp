#include <bits/stdc++.h>

void dfs(vector<int>& nums, vector<vector<int>>& subsets, vector<int> curr_subset, size_t i = 0)
{
	if (i == nums.size())
	{
		subsets.push_back(curr_subset);
		return;
	}

	// ignore the current element
	dfs(nums, subsets, curr_subset, i+1);
	
	// take the current element
	curr_subset.push_back(nums.at(i));
	dfs(nums, subsets, curr_subset, i+1);

	curr_subset.pop_back();
}

int main(void) {
	size_t n; cin >> n;

	vector<int> nums(n);
	for (size_t i = 0; i < n; ++i) cin >> nums[i];

	vector<vector<int>> subsets{};
	vector<int> curr_subset{};
	dfs(nums, subsets, curr_subset);

	for (auto subset : subsets)
	{
		cout << '{';
		if (subset.size() == 0) goto end_subset;

		print("{}", subset[0]);

		for (auto it = subset.begin()+1; it != subset.end(); ++it)
		{
			print(", {}", *it);
		}
end_subset:
		cout << '}';
		print("\n");
	}
}
