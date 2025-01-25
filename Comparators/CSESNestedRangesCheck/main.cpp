#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <limits>
#include <climits>
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
bool comparator(const pi a, const pi b) {
    if (a.f == b.f) return a.s>b.s;
    return a.f < b.f;
}
int main() { 
    setIO("");
    int N;
    cin >> N;
    vector <pi> v(N);
    vi contains(N), contained(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].f >> v[i].s;
    } 
    sort(all(v));
    int l = 0, r = 1;
    while (l < N && r < N) {
        if (v[l].s >= v[r].s) {
            contained[r] = 1;
            r++;
        }
        else {
            l = r;
            r++;
        }
    }
    for (auto ele: contained) {
        cout << ele << " ";
    }
}