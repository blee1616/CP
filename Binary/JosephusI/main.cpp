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

int main() { 
    setIO("");
    int N, div;
    cin >> N >> div;
    div++;
    vi v, surv;
    int extra = 0;
    for (int i = 1; i <= N; i++) {
        v.pb(i);
    }
    while (!v.empty()) {
        for (int i = 0; i < v.size(); i++) {
            if ((i-(div-1)+extra)%div != 0) {
                surv.pb(v[i]);
            }
            else {
                cout << v[i] << " ";
            }
        }
        extra += v.size() % div;
        v = surv;
        surv.clear();
    }
}