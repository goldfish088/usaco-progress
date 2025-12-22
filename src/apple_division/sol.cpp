#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dfs(vector<ll>& weights, ll s1=0, ll s2=0, size_t i = 0)
{
	if (i == weights.size()) return abs(s1-s2);

	return min(
		dfs(weights, s1 + weights[i], s2, i+1),
		dfs(weights, s1, s2 + weights[i], i+1)
	);
}

ll bitmask_solve(vector<ll>& weights)
{
	ll ans = INT64_MAX;
	ll n = weights.size();

	
	for (ll b = 1; b < (1<<n); ++b) {
		ll one = 0;
		ll two = 0;

		for (ll i = 0; i < n; ++i) {
			if (b & (1<<i)) {
				one += weights[i];
			} else {
				two += weights[i];
			}
		}

		ans = min(ans, abs(two - one));
	}

	return ans;
}

int main(void) {

	int n; cin >> n;

	vector<ll> weights(n);
	for (int i = 0; i < n; ++i) cin >> weights[i];

	// cout << dfs(weights) << endl;
	cout << bitmask_solve(weights) << endl;
}
