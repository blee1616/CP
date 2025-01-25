#include <cstdio>
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
int main() {
    setIO("hps");
    long long N,ans = 0;
    string s;
    cin >> N;
    vector <long long> H(N), P(N), S(N);
    vector <long long> preH(N+1), preP(N+1), preS(N+1);
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s == "H") H[i] = 1;
        else if (s == "P") P[i] = 1;
        else S[i] = 1;
    }
    preH = partial(H);
    preP = partial(P);
    preS = partial(S);
    long long max1,max2;
    for (int i = 0; i < N + 1; i++) {
        max1 = max(preH[i],max(preP[i],preS[i]));
        max2 = max (preH[N]-preH[i],max(preP[N]-preP[i],preS[N]-preS[i]));
        ans = max(ans, max1 + max2);
    }
    cout << ans;
}
