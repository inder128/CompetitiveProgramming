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

// implementation heavy;

void solve(){
    int n; cin>>n;
    vi arr(n); cin>>arr;
    bool sorted = true;
    vector <vi> ans;
    for (int i = 2; i <= n; ++i){
    	int occi = find(rng(arr), i) - arr.begin();
    	int occ1 = find(rng(arr), 1) - arr.begin();
    	vi lens, lens2;
    	if(sorted and occi < occ1){
    		lens.pb(occi);
    		lens.pb(occ1 - occi);
    		lens.pb(i - 1);
    		lens.pb(n - occ1 - i + 1);
    	}
    	else if(sorted and occi > occ1){
    		lens.pb(occ1);
    		lens.insert(lens.end(), i - 1, 1);
    		lens.pb(occi + 1 - i + 1 - occ1);
    		lens.pb(n - occi - 1);
    		sorted = false;
    	}
    	else if(!sorted and occi < occ1){
    		lens.pb(occi);
    		lens.pb(occ1 + 1 - i + 1 - occi);
    		lens.insert(lens.end(), i - 1, 1);
    		lens.pb(n - occ1 - 1);
    		sorted = true;
    	}
    	else{
    		lens.pb(occ1 + 1 - i + 1);
    		lens.pb(i - 1);
    		lens.pb(occi - occ1);
    		lens.pb(n - occi - 1);
    	}
    	
    	vi narr;
    	int lst = n;
    	reverse(rng(lens));
    	for(int ln : lens){
    		if(ln) lens2.pb(ln);
    		lst -= ln;
    		narr.insert(narr.end(), arr.begin() + lst, arr.begin() + lst + ln);
    	}
    	// db(lst);
    	reverse(rng(lens2));
    	ans.pb(lens2);
    	arr = narr;
    }
    if(!sorted){
    	ans.pb(vi(n, 1));
    	reverse(rng(arr));
    }
    // db(arr);

    cout<<ans.size()<<el;
    for(vi lens : ans){
    	cout<<lens.size()<<" ";
    	for(int ln : lens) cout<<ln<<" ";
    	cout<<el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}