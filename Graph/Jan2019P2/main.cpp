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

const int MAXN = 1005;

char grid[MAXN][MAXN];  // the grid itself
int n;
bool visited[MAXN][MAXN];  // keeps track of which nodes have been visited
ll currA =
    0;  // keeps track of the current area of the current blob of ice cream
ll currP = 0;  // keeps track of the current perimeter of the blob of ice cream
ll area = 0;
ll perimeter = 0;

void setIO(string name) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.length()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void floodfill(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) {
		currP++;
		return;  // if outside grid
	}
	if (visited[r][c]) return;  // already visited this square
	if (grid[r][c] == '.') {
		currP++;
		return;
	}
	visited[r][c] = true;  // mark current square as visited
	if (grid[r][c] == '#') { currA++; }
	// recursively call floodfill for neighboring squares
	floodfill(r, c + 1);
	floodfill(r, c - 1);
	floodfill(r - 1, c);
	floodfill(r + 1, c);
}

int main() {
	setIO("perimeter");
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { cin >> grid[i][j]; }
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && grid[i][j] == '#') {
				floodfill(i, j);
				if (area == currA) {
					perimeter = min(perimeter, currP);
				} else if (currA > area) {
					area = currA;
					perimeter = currP;
				}
				currA = currP = 0;
			}
		}
	}
	cout << area << " " << perimeter << endl;
	return 0;
}