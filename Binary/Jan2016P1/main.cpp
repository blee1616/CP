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
ll N,C;
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
bool possible(ll mid) {
    ll ind = 0;
    for (int i = 0; i < C; i++) {
        ll check = v[ind] + 2 * mid;
        while (check >= v[ind] && ind < N) {
            ind++;
        }
    }
    return ind == N;
}
int main() { 
    setIO("angry");
    cin >> N >> C;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort (all(v));
    ll lo = 1, high = 1e9;
    while (lo < high) {
        ll mid = (lo + high)/2;
        if (possible(mid)) {
            high = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << lo;
}