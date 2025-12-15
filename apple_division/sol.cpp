#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& weights, long long s1=0, long long s2=0, size_t i = 0)
{
	if (i == weights.size()) return abs(s1-s2);

	return min(
		solve(weights, s1 + weights[i], s2, i+1),
		solve(weights, s1, s2 + weights[i], i+1)
	);
}

int main(void) {

	int n; cin >> n;

	vector<long long> weights(n);
	for (int i = 0; i < n; ++i) cin >> weights[i];

	cout << solve(weights) << endl;
}
