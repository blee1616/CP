#include <bits/stdc++.h> //change the "-" to a "/"
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

int main() { 
    setIO("highcard");
    ll n, ans = 0;
    cin >> n;
    vi v1(n), v2;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    sort(all(v1));
    int ind = 0;
    for (int i = 1; i <= 2*n; i++) {
        if (i != v1[ind]) v2.pb(i);
        else ind++;
    }
    int ind1 = 0, ind2 = 0;
    while (ind1 < n && ind2 < n) {
        if (v2[ind2] > v1[ind1]) {
            ans++;
            ind1++,ind2++;
        }
        else {
            ind2++;
        }
    }
    cout << ans;
}