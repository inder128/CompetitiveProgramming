#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define ll long long
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

void solve(){
    int n; cin>>n;
    vi curr(n), req(n);
    vector <pi> arr;
    for (int i = 0; i < n; ++i){
        cin>>req[i];
        for (int j = 0; j < req[i]; ++j){
            int x; cin>>x;
            arr.pb({x, i});
        }
        req[i] = (req[i] + 1) / 2;
    }

    sort(rng(arr));

    if(n == 1 and req[0] == 1){
        cout<<arr[1].F - arr[0].F<<" 2\n";
        return;
    }

    int l = 0, cnt = 0, ans = 2e9, len = 0;
    for(int r = 0; r < SZ(arr); ++r){
        curr[arr[r].S]++;

        if(curr[arr[r].S] == req[arr[r].S]){
            cnt++;
        }

        while(curr[arr[l].S] > req[arr[l].S]){
            curr[arr[l].S]--;
            l++;
        }

        if(cnt < n) continue;
            
        int currAns = arr[r].F - arr[l].F;
        if(currAns > ans) continue;

        int currLen = upper_bound(rng(arr), make_pair(arr[r].F, n - 1)) - lower_bound(rng(arr), make_pair(arr[l].F, 0));

        if(currAns == ans){
            maxi(len, currLen);
        }

        if(currAns < ans){
            ans = currAns, len = currLen;
        }

    }

    cout<<ans<<" "<<len<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}