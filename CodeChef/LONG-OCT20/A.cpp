#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin>>n>>q;
    vector <int> v(n);
    for(int &i : v) cin>>i;

    vector <int> bmx(n, -1), fmx(n, n);
    stack <int> stk;
    for(int i = 0; i < n; i++){
        while(stk.size() and v[stk.top()] <= v[i])
            stk.pop();
        bmx[i] = i - (stk.size() ? stk.top() : -1);
        stk.push(i);
    }
    while(stk.size()) stk.pop();
    for(int i = n-1; i >= 0; i--){
        while(stk.size() and v[stk.top()] < v[i])
            stk.pop();
        fmx[i] = (stk.size() ? stk.top() : n) - i;
        stk.push(i);
    }

    vector <int> uv = v;
    sort(uv.begin(), uv.end());
    uv.resize(unique(uv.begin(), uv.end()) - uv.begin());
    function <int(int)> getID = [&](int a){
        return lower_bound(uv.begin(), uv.end(), a) - uv.begin();
    };
    vector <long long> count(uv.size());
    for(int i = 0; i < n; i++){
        count[getID(v[i])] += ((bmx[i]*1ll*fmx[i])*(bmx[i] + fmx[i]))/2;
    }

    for(int i = 1; i < uv.size(); i++){
        count[i] += count[i-1];
    }

    while(q--){
        int l, r; cin>>l>>r;
        int li = lower_bound(uv.begin(), uv.end(), l) - uv.begin() - 1;
        int ri = upper_bound(uv.begin(), uv.end(), r) - uv.begin() - 1;
        cout<<(ri >= 0 ? count[ri] : 0) - (li >= 0 ? count[li] : 0)<<"\n";
    }
    return 0;
}