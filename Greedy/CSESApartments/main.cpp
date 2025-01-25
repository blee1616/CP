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
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() { 
    setIO("");
    ll N, Q, k;
    cin >> N >> Q >> k;
    vi apart(Q), targets(N);
    for (int i = 0; i < N; i++) {
        cin >> targets[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> apart[i];
    }
    sort (all(targets)), sort(all(apart));
    ll ind1 = 0, ind2 = 0, ans = 0;
    while (ind1 < N && ind2 < Q) {
        if (targets[ind1] > apart[ind2]) {
            if (targets[ind1] - k <= apart[ind2]) {
                ans++;
                ind1++,ind2++;
            }
            else ind2++;
        }
        else {
            if (targets[ind1] + k >= apart[ind2]) {
                ans++;
                ind1++, ind2++;
            }
            else ind1++;
        }
    }
    cout << ans;
}
