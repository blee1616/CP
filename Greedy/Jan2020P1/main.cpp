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
    setIO("berries");
    ll N, Q;
    cin >> N >> Q;
    vi v(N);
    vi baskets(Q);
    fill(all(baskets),0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(all(v),greater<ll>());
    for (int i = 0; i < N; i++) {
        baskets[i] = v[i];
    }
    while (True) {
        ll div = 2, endpoint = 1; //midpoint-endpoint //use mod to account for remainders

        sort (all(baskets),greater<ll>());
        if (baskets[0] % 2 == 1) {
            if (baskets[0] / 2 + 1 < baskets[Q/2]) break;
        }
        else {
            if (baskets[0] / 2 < baskets[Q/2]) break;
        }