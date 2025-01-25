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

const int MAXN = 501;

ll grid[MAXN][MAXN];  // the grid itself
bool visited[MAXN][MAXN];  // keeps track of which nodes have been visited
ll row, col, x;
vector <pair<ll,ll>> targets;

void setIO(string name) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.length()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void floodfill(int r, int c, ll num, ll mid) {
	if (r < 0 || r >= row || c < 0 || c >= col) {
		return;  // if outside grid
	}
	if (visited[r][c]) return;  // already visited this square
    if (abs(num-grid[r][c]) > mid) return;
	visited[r][c] = true;  // mark current square as visited
	// recursively call floodfill for neighboring squares
	floodfill(r, c + 1, grid[r][c], mid);
	floodfill(r, c - 1, grid[r][c], mid);
	floodfill(r - 1, c, grid[r][c], mid);
	floodfill(r + 1, c, grid[r][c], mid);
}
bool possible(ll mid) {
    bool check = true;
    floodfill(targets[0].f,targets[0].s, grid[targets[0].f][targets[0].s], mid);
    for (int i = 0; i < targets.size(); i++) {
        check = check && visited[targets[i].f][targets[i].s];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            visited[i][j] = false;
        }
    }
    return check;
}
int main() {
	setIO("ccski");
	cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> x;
            if (x) {
                targets.pb({i,j});
            }
        }
    }
    ll lo = 0, high = INT_MAX, valid = 0;
    while (lo <= high) {
        ll mid = lo + (high-lo) / 2;
        if (possible(mid)) {
            valid = mid;
            high = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << valid;
}