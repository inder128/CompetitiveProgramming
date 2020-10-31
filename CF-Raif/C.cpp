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

// implementation heavy :(

void solve(){
    int n; cin>>n;
    vi p(n + 1);
    for (int i = 1; i <= n; ++i){
    	cin>>p[i];
    }
    

    set <pi> ans;
    vi fp(n + 1);
    vector <bool> taken1(n + 1), taken23(n + 1);
    for (int i = 1; i <= n; ++i){
    	if(p[i] != 1) taken1[i] = true;
    	if(p[i] < 2) taken23[i] = true;
    }
    int l23 = n, l1 = n, h = n;

    for (int c = n; c; --c){
    	if(p[c] == 0) continue;
    	else if(p[c] == 1){
    		ans.insert({h, c});
    		fp[c] = h;
    		h--;
    	}
    	else if(p[c] == 2){
    		while(l1 and taken1[l1]) l1--;
    		if(l1 < c){
    			cout<<"-1\n";
    			return;
    		}
    		fp[c] = fp[l1];
    		ans.insert({fp[l1], c});
    		taken1[l1] = true;
    	}
    	else{
    		while(l23 and taken23[l23]) l23--;
    		int l;
    		if(l23 <= c){
    			while(l1 and taken1[l1]) l1--;
	    		if(l1 < c){
	    			cout<<"-1\n";
	    			return;
	    		}
	    		taken1[l1] = true;
	    		l = l1;
    		}
    		else{
    			taken23[l23] = true;
    			l = l23;
    		}
    		fp[c] = h;
    		ans.insert({h, l});
    		ans.insert({h, c});	
    		h--;
    	}
    }

    cout<<ans.size()<<el;
    for(pi p : ans) cout<<p.F<<" "<<p.S<<el;
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