#include <bits/stdc++.h>
using namespace std; 

int main() {
    freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
    ios_base::sync_with_stdio(0);
	cin.tie(0); // put the name here
    // put code here
    long long N, ans = 0;
    cin >> N;
    vector <long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end(), greater <long long>());
    for (int i = 0; i < N; i++) {
        if (v[i] > i - 1) ans++;
    }
    cout << ans;
}