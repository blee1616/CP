#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, ans = 1;
    cin >> n;
    vector <long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n-1; i++) {
        if (v[i] != v[i+1]) ans++;
    }
    cout << ans;
}