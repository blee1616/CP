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
const ll maxn = 1e5;
bool visited[maxn];
vector <vector<ll>> adj(maxn);
vector <pi> coord(maxn);
vector <vector<ll>> connected;
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
void dfs (ll node, ll ind) {
	visited[node] = true;
	connected[ind].pb(node);
	for (ll next: adj[node]) {
		if (!visited[next]) {
			dfs(next,ind);
		}
	}
}
int main() { 
    setIO("fenceplan");
    ll N, Q, a, b, ind = 0;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> coord[i].f >> coord[i].s;
	}
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			connected.pb({i});
			dfs(i,ind);
		}
		ind++;
	}
	ll mini = 1e18;
	for (auto ele: connected) {
		for (auto x: ele) {
			cout << x << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < connected.size(); i++) {
		ll maxX = coord[connected[i][0]].f, minX = coord[connected[i][0]].f, 
		maxY = coord[connected[i][0]].s, minY = coord[connected[i][0]].s;
		for (int j = 0; j < connected[i].size(); j++) {
			maxX = max(maxX,coord[connected[i][j]].f);
			minX = min(minX,coord[connected[i][j]].f);
			maxY = max(maxY,coord[connected[i][j]].s);
			minY = min(minY,coord[connected[i][j]].s);
		}
		mini = min(mini,(maxX-minX)*(maxY-minY));
	}
	cout << mini;
}