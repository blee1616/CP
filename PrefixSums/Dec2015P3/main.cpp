#include <iostream>
#include <vector>
using namespace std;

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

int main () {
    setIO("bcount");
    int N, Q, val,x,y;
    cin >> N >> Q;
    vector <long long> H(N),G(N),J(N);
    for (int i = 0; i < N; i++) {
        cin >> val;
        if (val == 1) {
            H[i] = 1;
            G[i] = 0;
            J[i] = 0;
        }
        else if (val == 2) {
            H[i] = 0;
            G[i] = 1;
            J[i] = 0;
        }
        else {
            H[i] = 0;
            G[i] = 0;
            J[i] = 1;
        }
    }
    vector <long long> Hpartial = partial(H);
    vector <long long> Gpartial = partial(G);
    vector <long long> Jpartial = partial(J);
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        cout << Hpartial[y]-Hpartial[x-1] << " " << Gpartial[y]-Gpartial[x-1] << " " << Jpartial[y] - Jpartial[x-1] << endl;
    }
}
