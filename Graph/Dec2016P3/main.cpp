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
const ll maxN = 200;
bool visited[maxN];
ll ans = 0;
vector <vector<ll>> adj(maxN);
void dfs (ll node) {
    visited[node] = true;
    for (ll next: adj[node]) {
        if (!visited[next]) {
            ans++;
            dfs(next);
        }
    }
}
int main() { 
    setIO("moocast");
    ll N,x,y,z,p;
    ll max1 = 0;
    cin >> N;
    vector <pi> coords(N);
    vector <ll> powers(N);
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> powers[i];
        coords[i] = mp(x,y);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                if (sqrt(pow(coords[i].f - coords[j].f, 2) + pow(coords[i].s - coords[j].s, 2) * 1.0) <= powers[i]) adj[i].pb(j);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        ans = 1;
        dfs(i);
        max1 = max(ans,max1);
        for (int i = 0; i < N; i++) {
            visited[i] = false;
        }
    }
    cout << max1;
}