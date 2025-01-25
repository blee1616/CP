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
vector <pair <ll,ll>> v;
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
bool possible(ll diff,ll N,ll Q) {
    ll ind = 0;
    ll first = v[ind].f;
    ll cows = 1;
    while (ind < Q) {
        if (first + diff <= v[ind].s) {
            cows++;
            first = first + diff;
        }
        else {
            ind++;
            while (first + diff > v[ind].s && ind < Q) ind++;
            if (ind==Q) break;
            if (first + diff <= v[ind].f) {
                first = v[ind].f;
            }
            else if (first + diff <= v[ind].s) {
                first = first + diff;
            }
            cows++;
        }
    }
    return cows >= N;
}
ll binSearch(ll min,ll max,ll N, ll Q) {
    if (min==max) return min;
    if (min + 1 == max) {
        if (possible(max,N,Q)) return max;
        return min; 
    }
    ll mid = (min + max)/2;
    if (possible(mid,N,Q)) return binSearch(mid,max,N,Q);
    else return binSearch(min,mid,N,Q);
}
int main() { 
    setIO("socdist");
    ll N, Q,x,y;
    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    sort(all(v));
    ll min = 1, max = 1e18;
    cout << binSearch(min,max,N,Q);
}
