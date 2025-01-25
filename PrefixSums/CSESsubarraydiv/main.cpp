#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long pre = 0, n, temp, ans = 0;
    cin >> n;
    vector <long long> v(n);
    map <long long, int> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp < 0) {
            v[i] = temp % n + n;
        }
        else {
            v[i] = temp % n;
        }
    }
    m[0] = 1;
    for (long long x: v) {
        pre = (pre + x) % n;
        ans += m[pre];
        m[pre]++;
    }
    cout << ans;
}