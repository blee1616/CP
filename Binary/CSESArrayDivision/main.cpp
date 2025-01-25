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
#include <iterator>
#include <limits>
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
vi v;
ll N, t;
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
bool possible(ll diff) {
    ll currSum = 0, tot = 1;
    for (int i = 0; i < N; i++) {
        if (v[i] > diff) {
            return false;
        }
        else if (currSum + v[i] > diff) {
            tot++;
            currSum = v[i];
        }
        else {
            currSum += v[i];
        }
    }
    return tot <= t;
}
int main() {
	setIO();
    ll x;
	cin >> N >> t;
	for (int i = 0; i < N; i++) { 
        cin >> x;
        v.pb(x);
    }
	ll lo = 1;
	ll hi = 1e18;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		ll sum = 0;
        if (possible(mid)) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
	}
	cout << lo << "\n";
}