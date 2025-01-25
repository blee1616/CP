#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_SIDE = 1000;
int pref[MAX_SIDE+1][MAX_SIDE+1];
int barn[MAX_SIDE+1][MAX_SIDE+1];
/*
vector<vector<int>> computePrefixSums(const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Create a prefix sum grid with an extra row and column
    vector<vector<int>> prefixSums(rows + 1, vector<int>(cols + 1, 0));

    // Compute prefix sums for the first row
    for (int j = 1; j <= cols; ++j) {
        prefixSums[1][j] = prefixSums[1][j - 1] + grid[0][j - 1];
    }

    // Compute prefix sums for the first column
    for (int i = 1; i <= rows; ++i) {
        prefixSums[i][1] = prefixSums[i - 1][1] + grid[i - 1][0];
    }

    // Compute prefix sums for the remaining cells
    for (int i = 2; i <= rows; ++i) {
        for (int j = 2; j <= cols; ++j) {
            prefixSums[i][j] = prefixSums[i - 1][j] + prefixSums[i][j - 1] - prefixSums[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }

    return prefixSums;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 0,-1},
        {0, 0, 0,0},
        {0, 0, 0,0},
        {-1,0,0,1}
    };

    vector<vector<int>> prefixSums = computePrefixSums(grid);

    // Print the prefix sums grid
    for (const auto& row : prefixSums) {
        for (const int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
*/
int main () {
    freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long K,N;
    cin >> N >> K;
    int x1,x2,y1,y2;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        barn[x1][y1]++;
        barn[x2][y1]--;
        barn[x1][y2]--;
        barn[x2][y2]++;
    }
    for (int i = 1; i < MAX_SIDE; i++) {
		for (int j = 1; j < MAX_SIDE; j++) {
			pref[i][j] = barn[i][j] + pref[i - 1][j] +
			                  pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}
    for (const auto&row: pref) {
        for (const int val: row) {
            if (val == K) {
                ans++;
            }
        }
    }
    cout << ans;
}
