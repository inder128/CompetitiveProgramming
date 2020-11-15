#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define int long long
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
    int n, w; cin>>n>>w;
    vector <pi> arr(n);
    for (int i = 0; i < n; ++i){
    	cin>>arr[i].F;
    	arr[i].S = i;
    }
    sort(rng(arr));
    if(arr[0].F > w){
    	cout<<"-1\n";
    	return;
    }
    int h = (w + 1) / 2, sum = 0;
    vi inds;
    for (int i = 0; i < n and arr[i].F <= w; ++i){
    	if(arr[i].F >= h){
    		cout<<1<<el;
    		cout<<arr[i].S + 1<<el;
    		return;
    	}
        if(sum + arr[i].F <= w){
        	sum += arr[i].F;
        	inds.pb(arr[i].S + 1);
        }
    }
    if(sum < h){
    	cout<<"-1\n";
    	return;
    }
    cout<<inds.size()<<el;
    for(int i : inds) cout<<i<<" "; cout<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}