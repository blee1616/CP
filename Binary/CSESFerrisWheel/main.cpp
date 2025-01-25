#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, count = 0;
    long long cap;
    vector <long long> v;
    cin >> n >> cap;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int p1 = 0, p2 = n-1;
    while(p1 <= p2) {
        if (v[p1] + v[p2] <= cap) {
            p1++;
        }
        p2--;
        count++;
    }
    cout << count;
}