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
    setIO("pairup");
    ll N, x, y;
    cin >> N;
    vector <pi> v(N);
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        v[i] = mp(y,x);
    }
    sort(v.begin(),v.end());
    int left = 0, right = N-1;
    ll ans = 0;
    while (v[right].f >= v[left].f) {
        ans = max(ans,v[right].f + v[left].f);
        if (v[right].s == v[left].s) {
            left++,right--;
        }
        else if (v[right].s > v[left].s) {
            v[right].s -= v[left++].s;
        }
        else {
            v[left].s -= v[right--].s;
        }
    }
    cout << ans;
}