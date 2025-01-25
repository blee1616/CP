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

const int MAX_N = 1000;

vector <string> grid;  // the grid itself
int row_num;
int col_num;
bool visited[MAX_N][MAX_N];  // keeps track of which nodes have been visited
string ans = "";
ll num, minimum = 1e9;
void floodfill(int r, int c, string str) {
	if ((r < 0 || r >= row_num || c < 0 || c >= col_num)  // if out of bounds
	    || (grid[r][c] != '.' && grid[r][c] != 'B' && grid[r][c] != 'A')                         // wrong color
	    || visited[r][c]  // already visited this square
	)
		return;
    if (grid[r][c] == 'B') {
        if (str.length() < minimum) {
            ans = str;
            minimum = str.length();
        }
    }
	visited[r][c] = true;  // mark current square as visited        // increment the size for each square we visit

	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, str + "R");
	floodfill(r, c - 1, str + "L");
	floodfill(r - 1, c, str + "U");
	floodfill(r + 1, c, str + "D");
}
int main() {
    cin >> row_num >> col_num;
	/*
	 * input code and other problem-specific stuff here
	 */
    ll count = 0;
    grid.resize(row_num);
    for(int i = 0; i < row_num; i++) {
        cin >> grid[i];
    }
	for (int i = 0; i < row_num; i++) {
		for (int j = 0; j < col_num; j++) {
            if (grid[i][j] == 'A') {
                floodfill(i,j,"");
                break;
            }
        }
    }
	if (minimum == 1e9) cout << "NO";
    else {
        cout << "YES" << endl << minimum << endl << ans;
    } 
}