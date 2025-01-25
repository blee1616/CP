#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// the argument is the input filename without the extension
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

vector <long long> partial(const vector <long long> &a) {
	vector <long long> psum(a.size() + 1);
	for (int i = 0; i < a.size(); ++i) {
        psum[i + 1] = psum[i] + a[i];
    }
	return psum;
}
long long solve (const vector <long long> &vec, int N) {
    long long ind, ans = 0;
    for (int i = 0; i < N; i++) {
        ind = 0;
        for (int j = N; j > N - i - 1; j--) {
            if ((vec[j] - vec[i - ind]) % 7 == 0) {
                return j - i + ind;
            }
            ind++;
        }
    }
    return ans;
}
int main() {
	setIO("div7");
	int N;
    cin >> N;
    vector <long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    vector <long long> part = partial(v);
    cout << solve(part, N);
}
