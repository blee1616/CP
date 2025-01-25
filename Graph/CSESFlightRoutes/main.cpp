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

using pi = pair<ll,ll>;
#define f first
#define s second
#define mp make_pair
ll ans = 1;
ll ans1 = 1;
const ll maxN = 100000;
bool visited[maxN];
bool visited1[maxN];
vector <vector<ll>> adj(maxN);
vector <vector<ll>> adj1(maxN);
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
void dfs(ll node) {
    visited[node] = true;
    for (ll next: adj[node]) {
        if (!visited[next]) {
            ans++;
            dfs(next);
        }
    }
}
void dfs1(ll node) {
    visited1[node] = true;
    for (ll next: adj1[node]) {
        if (!visited1[next]) {
            ans1++;
            dfs1(next);
        }
    }
}
int main() { 
    setIO("");
    ll N,M,a,b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--,b--;
        adj[a].pb(b);
        adj1[b].pb(a);
    }
    dfs(0);
    if (ans == N) {
        dfs1(0);
        if (ans1 == N) cout << "YES" << endl;
        else {
            cout << "NO" << endl;
            for (int i = 0; i < N; i++) {
                if (!visited1[i]) {
                    cout << i+1 << " 1";
                    break;
                }
            }
        }
    }
    else {
        cout << "NO" << endl;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                cout << "1 " << i+1;
                break;
            }
        }
    }
}