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

const int MAX_N = 100;

vector <string> grid;  // the grid itself
int row_num;
const int col_num = 10;
bool visited[MAX_N][10];  // keeps track of which nodes have been visited
vector<pair<int,int>> connected;
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
void floodfill(int r, int c, char color) {
	if ((r < 0 || r >= row_num || c < 0 || c >= col_num)  // if out of bounds
	    || grid[r][c] != color                            // wrong color
	    || visited[r][c]  // already visited this square
	)
		return;

	visited[r][c] = true;  // mark current square as visited        // increment the size for each square we visit
    connected.pb({r,c});
	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}

int main() {
    setIO("mooyomooyo");
    ll amount;
    cin >> row_num >> amount;
	/*
	 * input code and other problem-specific stuff here
	 */
    grid.resize(row_num);
    for(int i = 0; i < row_num; i++) {
        cin >> grid[i];
    }
    while(true) {
        ll count = 0;
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                if (!visited[i][j] && grid[i][j] != '0') {
                    /*
                    * start a flood fill if the square hasn't already been visited,
                    * and then store or otherwise use the component size
                    * for whatever it's needed for
                    */
                    floodfill(i, j, grid[i][j]);
                    if (connected.size() >= amount) {
                        for (int k = 0; k < connected.size(); k++) {
                            grid[connected[k].f][connected[k].s] = '0';
                        }
                        count++;
                    }
                    connected.clear();
                }
            }
        }
        for (int i = 0; i < col_num; i++) {
            for (int j = row_num-1; j >= 0; j--) {
                if (grid[j][i]) {
                    int ind = j;
                    while (ind < row_num-1) {
                        if (grid[ind+1][i] == '0') {
                            grid[ind+1][i] = grid[ind][i];
                            grid[ind][i] = '0';
                            ind++;
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                visited[i][j] = false;
            }
        }
        if (!count) break;
    }
    for (auto ele: grid) {
        cout << ele << endl;
    }
}