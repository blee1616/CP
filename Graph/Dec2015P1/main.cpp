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

int N;
int litRooms = 1;
const int MN = 100;
bool visited[MN][MN];
bool illuminated[MN][MN];
vector<pair<int, int>> switches[MN][MN];

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

// Checks if a room is connected to the main component
bool checkConnected(int x, int y) {
	// Iterate through neighbors
	for (int i = 0; i < 4; i++) {
		int newX = x + dirX[i];
		int newY = y + dirY[i];

		// Ignore neighbor if out of bounds
		if (newX < 0 || newY < 0 || newX > N - 1 || newY > N - 1) { continue; }

		// If a neighbor is visited, return true
		if (visited[newX][newY]) { return true; }
	}

	// If no neighbors have been visited, return false
	return false;
}

// Floodfill method with source room (x,y)
void floodfill(int x, int y) {
	// Ignore this room if its out of bounds, already been visited, or isn't lit
	if (x < 0 || y < 0 || x > N - 1 || y > N - 1 || visited[x][y] ||
	    !illuminated[x][y]) {
		return;
	}

	/*
	 * Ignore room if it isn't connected to main component
	 * (i.e. it's inaccessible to Bessie)
	 * Don't return on coordinate (1, 1)
	 */
	if (!checkConnected(x, y) && !(x == 0 && y == 0)) { return; }

	// Set room to visited
	visited[x][y] = true;

	// Iterate through neighbors and floodfill from them
	for (int i = 0; i < 4; i++) { floodfill(x + dirX[i], y + dirY[i]); }

	// Turn on all lights from current room
	for (int i = 0; i < switches[x][y].size(); i++) {
		int roomX = switches[x][y][i].first;
		int roomY = switches[x][y][i].second;

		/*
		 * If room hasn't been lit yet, add it to our count of rooms that have
		 * been lit
		 */
		if (!illuminated[roomX][roomY]) { litRooms++; }

		// Set room led to by switch to lit
		illuminated[roomX][roomY] = true;

		// Floodfill from new room that is lit
		floodfill(roomX, roomY);
	}
}

int main() {
	setIO("lightson");

	int m;
	cin >> N >> m;

	// Take in input and add switches to corresponding room
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		switches[x - 1][y - 1].push_back({a - 1, b - 1});
	}

	// Set the top left room to lit (since it's lit initially)
	illuminated[0][0] = true;

	// Start floodfill from top-left room
	floodfill(0, 0);

	cout << litRooms << endl;
}