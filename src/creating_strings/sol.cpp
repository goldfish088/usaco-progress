#include <bits/stdc++.h>
using namespace std;

void find_all_perms(string& s, string& curr_perm, set<string>& permutations, vector<bool>& used) {
	if (curr_perm.size() == s.size()) {
		permutations.insert(curr_perm);
		return;
	}

	for (size_t i = 0; i < s.size(); ++i) {
		if (!used[i]) {
			used[i] = true;
			curr_perm.push_back(s[i]);

			find_all_perms(s, curr_perm, permutations, used);

			used[i] = false;
			curr_perm.pop_back();
		}
	}
}

bool try_permute(string& s, set<string>& all_perms) {
	// we know |s| <= 20
	int n = static_cast<int>(s.size());

	// the index just before the "decreasing" suffix
	int i = n-1;
	while (0 < i && s[i-1] >= s[i]) {
		i--;
	}
	
	// no more permutations starting from s
	if (i == 0) return false;

	// since [i, n) is already sorted, find the rightmost index with value larger than s[i]
	int j = n-1;
	while (0 < j && s[j] <= s[i-1]) {
		j--;
	}
	swap(s[i-1], s[j]);

	// [i, n) is still sorted, but to get the "next" permutation we need to reverse the sort
	reverse(s.begin()+i, s.end());

	all_perms.insert(s);
	return true;
}

int main(void) {
	string s; cin >> s;
	sort(s.begin(), s.end());

	set<string> permutations;

	// solution 1: backtracking
	{
		// vector<bool> used(s.size(), false);
		// string curr_perm{};
		// find_all_perms(s, curr_perm, permutations, used);
	}

	// solution 2: repeated "next permutation"
	{
		permutations.insert(s);
		while (try_permute(s, permutations));
	}

	cout << permutations.size() << '\n';
	for (auto p : permutations) {
		cout << p << '\n';
	}
	cout.flush();
}
