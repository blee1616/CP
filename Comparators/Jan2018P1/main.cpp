#include <bits-stdc++.h>
using namespace std;
typedef std::vector<long long>::iterator iter;
int main () {

    long long N,Q,changeInd,newVal,ogSum = 0,sortedInd,ogVal,newInd;
    cin >> N;
    vector <long long> v(N), sorted(N), pre(N+1);
    vector <pair <long long, long long>> m(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    cin >> Q;
    sorted = v;
    sort(sorted.begin(),sorted.end());
    pre[0] = 0;
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i-1] + sorted[i-1];
    }
    for (int i = 0; i < N; i++){
        iter low = lower_bound(sorted.begin(), sorted.end(), v[i]);
        m[i] = make_pair(low-sorted.begin(),v[i]);
    }
    for (int i = 0; i < N; i++) {
        ogSum += (i+1) * sorted[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> changeInd >> newVal;
        sortedInd = m[changeInd-1].first;
        ogVal = m[changeInd-1].second;
        iter x = lower_bound(sorted.begin(), sorted.end(), newVal);
        newInd = x-sorted.begin()-(bool) (newVal > ogVal);
        if (newInd == sortedInd){
            cout << ogSum + (newInd + 1)*(newVal-ogVal);
        }
        else if (newVal > ogVal) {
            cout << ogSum + (newInd + 1)*newVal - ogVal*(sortedInd+1) - pre[newInd+1] + pre[sortedInd+1];
        }
        else {
            cout << ogSum + (newInd + 1)*newVal - ogVal*(sortedInd+1) + pre[sortedInd] - pre[newInd];
        }
        cout << endl;
        //sorted[newInd] = ogVal;
        //sort(sorted.begin(),sorted.end());
    }
}
