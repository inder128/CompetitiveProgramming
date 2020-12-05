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
    int q; cin>>q;
    while(q--){
    	int b, w; cin>>b>>w;
    	int mx = max(b, w), mn = min(b, w);
    	if(mx > 3*mn + 1){
    		cout<<"NO\n";
    		continue;
    	}
    	vector <pi> cells;
    	for(int i = 2; i < 2*mn + 2; ++i){
    		cells.pb({2, i});
    	}
    	mx -= mn;
    	for(int j = 3; j < 2*mn + 2 and mx; j += 2, mx--){
    		cells.pb({1, j});
    	}
    	for(int j = 3; j < 2*mn + 2 and mx; j += 2, mx--){
    		cells.pb({3, j});
    	}
    	if(mx) cells.pb({2, 2*mn + 2});
    	if(b > w){
    		for(auto &pr : cells){
    			pr.F++;
    		}
    	}
    	// db(w, b);
    	assert(cells.size() == w + b);
    	for(auto pr : cells){
    		if(pr.F % 2 == pr.S % 2){
    			w--;
    		}
    		else{
    			b--;
    		}
    	}
    	// db(w, b);
    	assert(w == 0 and b == 0);
    	cout<<"YES\n";
    	for(auto pr : cells){
    		cout<<pr.F<<" "<<pr.S<<el;
    	}
    }
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