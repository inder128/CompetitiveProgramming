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

// tricky time complexity;
// maximise the sum of three mutually coprime integers;

void solve(){
    int n; cin>>n;
    vi arr(n); cin>>arr;
    sort(rng(arr));
    arr.resize(unique(rng(arr)) - arr.begin());
    n = arr.size();

    int ans = arr.back();

    // time complexity -> O(n*log(n) + n*n^(1 / 3)*n^(1 / 3));
    for(int a = 0; a < n; ++a){
    	int l = -1;
    	for(int b = a - 1; b > l; b--){
    		if(arr[a] % arr[b] == 0) continue;
    		maxi(ans, arr[a] + arr[b]);
    		for(int c = b - 1; c > l; --c){
    			if(arr[a] % arr[c] == 0) continue;
    			if(arr[b] % arr[c] == 0) continue;
    			maxi(ans, arr[a] + arr[b] + arr[c]);
    			l = c;
    			break;
    		}
    	}
    }

    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}