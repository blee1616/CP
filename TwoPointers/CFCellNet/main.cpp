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
    ll n,m,ans = 0;
    vector<ll>::iterator low;
    cin >> n >> m;
    vi cities(n), nets(m);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> nets[i];
    }
    for (int i = 0; i < n; i++) {
        low = lower_bound(nets.begin(),nets.end(), cities[i]);
        ll position = low-nets.begin();
        if (position == 0) ans = max(ans,nets[position]-cities[i]);
        else if (position == m) ans = max (ans,cities[i]-nets[position-1]);
        else ans = max(ans,min(nets[position]-cities[i],cities[i]-nets[position-1]));
    }
    cout << ans;
}