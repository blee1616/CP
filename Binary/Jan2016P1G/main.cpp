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
ll N;
vi v,diffs;
const double MaxError = 10e-2;
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
bool possible (double diff) {

}
int main() { 
    setIO("angry");
    cin >> N;
    v.resize(N);
    diffs.resize(N-1);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(all(v));
    for (int i = 0; i < N-1; i++) {
        diffs[i] = v[i+1] - v[i];
    }
    
    double lo = 0;
    double hi = 
    while ()
}