#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("stacking");
    int N, Q, a, b;
    cin >> N >> Q;
    vector <long long> v(N+1),vec(N+1);
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        v[a-1]++;
        v[b]--;
    }
    for (int i = 1; i <= N; i++) {
        vec[i] = vec[i-1] + v[i];
    }
    sort(vec.begin(),vec.end());
    cout << vec[vec.size()/2];
}

