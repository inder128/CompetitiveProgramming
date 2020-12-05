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
    int n; cin>>n;
    vi arr(n); cin>>arr;
    map <int, vi> inds;
    for(int i = 0; i < n; ++i){
    	inds[arr[i]].pb(i);
    }
    vi mxPre = arr;
    for(int i = 1; i < n; ++i){
    	mxPre[i] = max(mxPre[i - 1], arr[i]);
    }
    vi mxSuff = arr;
    for(int i = n - 2; i >= 0; --i){
    	mxSuff[i] = max(mxSuff[i + 1], arr[i]);
    }

    vi nextSmaller(n);
    vector <pi> stk;
    for(int i = n - 1; i >= 0; --i){
    	if(stk.empty() or stk[0].F >= mxPre[i]){
    		nextSmaller[i] = n;
    	}
    	else{
    		pi pr = {mxPre[i], 0};
    		int j = lower_bound(rng(stk), pr) - stk.begin() - 1;
    		nextSmaller[i] = stk[j].S;
    	}
    	while(stk.size() and stk.back().F >= arr[i]){
    		stk.pop_back();
    	}
    	stk.pb({arr[i], i});
    }

    // db(nextSmaller);


    for(int i = 0; i < n - 2; ++i){
    	int j = nextSmaller[i];
    	if(j == n or mxSuff[j] != mxPre[i]) j--;
    	if(j - i < 2 or mxSuff[j] != mxPre[i]){
    		continue;
    	}

    	// db(i, 1);
    	auto itr = upper_bound(rng(inds[mxPre[i]]), i);
    	if(itr == inds[mxPre[i]].end() or (*itr) >= j) continue;

    	// db(i);

    	cout<<"YES\n";
    	cout<<(i + 1)<<" "<<(n - (i + 1) - (n - j))<<" "<<(n - j)<<el;
    	return;
    }

    cout<<"NO\n";
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