#include <bits/stdc++.h> //change the "-" to a "/"
using namespace std;


using ll = long long;

using vi = vector<pair <ll,ll>>;
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
bool comp (pair <ll,ll> a, pair <ll,ll> b) {
    return a.s > b.s;
}
int main() { 
    setIO("reststops");
    ll L, n, s1, s2, x, y;
    cin >> L >> n >> s1 >> s2;
    ll diffpermeter = s1-s2;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v[i] = mp(x,y);
    }
    vi sorted = v;
    sort(all(v),comp);
    sort (all(sorted));
    ll ind1 = 0, ind2 = 0, ans = 0;
    while (v[ind1] != sorted[n-1]) {
        if (ind1 == 0 && ind2 == 0) {
            ans += diffpermeter*v[ind2].s*v[ind2].f;
        }
        else if (v[ind1].f < v[ind2].f) {
            ans += diffpermeter*v[ind2].s*(v[ind2].f-v[ind1].f);
            ind1 = ind2;
        }
        ind2++;
    }
    cout << ans;
}
