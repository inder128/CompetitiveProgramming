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

// wrong soln;
// check correct soln in E.cpp;
// hint in limits;

void solve(){
    int n, k; cin>>n>>k;
    vi a(n); cin>>a;
    int l = 1, r = 1e6, sz;
    while(l <= r){
    	int m = (l + r)>>1;
    	int comps = 0;
    	for (int i : a){
    		comps += (i + m - 1)/m;
    	}
    	if(comps <= k){
    		r = m - 1;
    		/*
			this is wrong because it might happen that this condition never becomes true :-
			EX -> n = 2, k = 5, a = [20,60];

			hint was given in limits;
			The could have given large value of k if this algo (binary search) worked;
			instead k was 1e6, this means solution is O(k) not O(n*log(k));
    		*/
    		if(comps == k) sz = m;
    	}
    	else{
    		l = m + 1;
    	}
    }

    int ans = 0;
    for(int i : a){
    	int gp = (i + sz - 1)/sz;
    	if(gp == 1){
    		ans += i*i;
    	}
    	else{
    		ans += (i%gp)*(i/gp + 1)*(i/gp + 1);
    		ans += (gp - i%gp)*(i/gp)*(i/gp);
    	}
    }
    cout<<ans<<el;
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