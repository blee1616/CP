#include <bits/stdc++.h> // see /general/running-code-locally
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
    setIO("");
    ll N, Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> N;
        vector <ll> v(N);
        for (int j = 0; j < N; j++) {
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        ll x = (N-1) / 2;
        ll ind = 0;
        ll change = 0;
        ll sign = -1;
        while (ind < N) {
            cout << v[x + change*sign] << " ";
            if (ind % 2 == 0) change++;
            ind++;
            sign *= -1;
        }
        cout << endl;
    }
}