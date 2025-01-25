#include <bits-stdc++.h> //change the "-" to a "/"
using namespace std;

using ll = long long;

using vi = vector<int>;
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
    if (a.f == b.f) return a.s < b.s;
    return a.f < b.f;
}
int main() {
    setIO("helpcross");
    ll c,n,x,y,ans = 0;
    cin >> c >> n;
    vector <ll> v1(c);
    vector <pair <ll,ll>> v2(n);
    for (int i = 0; i < c; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v2[i] = mp(x,y);
    }
    sort (all(v1));
    sort (all(v2), comp);
    ll ind1 = 0, ind2 = 0;
    while (ind1 < c && ind2 < n) {
        if (v2[ind2].f <= v1[ind1] && v2[ind2].s >= v1[ind1]) {
            ans++;
            ind1++,ind2++;
        }
        else if (v2[ind2].f > v1[ind1]) ind1++;
        else {
            ind2++;
        }
    }
    cout << ans;
    /*
   vector <pair <ll,ll>> v1 = {{1,4},{1,2},{2,3},{1,3}};
   sort(all(v1),comp);
   for (auto val: v1) {
        cout << val.f << " " << val.s << endl;
   }
   */
}