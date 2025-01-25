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
bool visited[105][105];
bool roads[105][105][105][105];
ll N;
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
void floodfill (int r, int c) {
    if (r < 1 || r > N || c < 1 || c > N || visited[r][c]) {
        return;
    }
    visited[r][c] = true;
    if (!roads[r][c][r+1][c]) floodfill(r+1,c);
    if (!roads[r][c][r-1][c]) floodfill(r-1,c);
    if (!roads[r][c][r][c+1]) floodfill(r,c+1); 
    if (!roads[r][c][r][c-1]) floodfill(r,c-1);
}
int main() { 
    setIO("countcross");
    ll R, C;
    ll a, b, c, d, x, y, pairs = 0;
    cin >> N >> C >> R;
    vector <pair<ll,ll>> cows;
    for (int i = 0; i < R; i++) {
        cin >> a >> b >> c >> d;
        roads[a][b][c][d] = true;
        roads[c][d][a][b] = true;
    }
    for (int i = 0; i < C; i++) {
        cin >> x >> y;
        cows.pb({x,y});
    }
    for (int i = 0; i < C; i++) {
        floodfill(cows[i].f,cows[i].s);
        for (int j = 0; j < C; j++) {
            if (!visited[cows[j].f][cows[j].s]) {
                pairs++;
            }
        }
        for (int j = 0; j < N+1; j++) {
            for (int k = 0; k < N+1; k++) {
                visited[j][k] = false;
            }
        }
    }
    cout << pairs/2;
}