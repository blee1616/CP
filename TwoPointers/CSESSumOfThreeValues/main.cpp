#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

using ll = long long;

using vi = vector<ll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() { 
    setIO("");
    ll N, Q, target;
    vector<pi> values;
    cin >> N >> target;
    for (int i = 0; i < N; i++) {
        cin >> Q;
        values.pb({Q,i+1});
    }
    sort(values.begin(), values.end());
    for (int i = 0; i < N; i++) {
        int left = i + 1, right = N-1;
        while (left < right) {
            if (values[i].first + values[left].first + values[right].first > target) {
			right--;
		} else if (values[i].first + values[left].first + values[right].first < target) {
			left++;
		} else if (values[i].first + values[left].first + values[right].first == target) {
			cout << values[i].second << " " << values[left].second << " " << values[right].second << endl;
			return 0;
		}
        }
    }
    cout << "IMPOSSIBLE";
}