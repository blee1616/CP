#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

using ll = long long;

using vi = vector<ll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<ll,ll>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // se4 8e /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	int n, target;
	cin >> n >> target;

	vector<pair<int, int>> values;
	// append the element and its index
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		values.push_back({x, i + 1});
	}

	sort(values.begin(), values.end());
	int left = 0;
	int right = n - 1;
	while (left < right) {
		// adjust left and right pointers
		if (values[left].first + values[right].first > target) {
			right--;
		} else if (values[left].first + values[right].first < target) {
			left++;
		} else if (values[left].first + values[right].first == target) {
			cout << values[left].second << " " << values[right].second << endl;
			return 0;
		}
	}

	// print IMPOSSIBLE if we haven't found a pair
	cout << "IMPOSSIBLE" << endl;
}