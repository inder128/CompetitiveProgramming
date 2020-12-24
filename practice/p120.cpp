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

// https://codeforces.com/problemset/problem/1153/E
// see submissions;

int q(int x1, int y1, int x2, int y2){
    cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<el; cout.flush();
    int res; cin>>res;
    assert(res >= 0);
	return res % 2;
}

void print(int x1, int y1, int x2, int y2){
	assert(q(x1, y1, x1, y1) == 1 and q(x2, y2, x2, y2) == 1);
    cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<el; cout.flush();
}


void solve(){
    int n; cin>>n;

    vi cols, rows;
    for(int j = 1; j <= n; ++j){
    	if(q(1, j, n, j)){
    		cols.pb(j);
    	}
    }
    for(int i = 1; i <= n; ++i){
    	if(q(i, 1, i, n)){
    		rows.pb(i);
    	}
    }

    if(SZ(rows) == 2 and SZ(cols) == 2){
    	if(q(rows[0], cols[0], rows[0], cols[0]) == 1){
    		print(rows[0], cols[0], rows[1], cols[1]);
    	}
    	else{
    		print(rows[0], cols[1], rows[1], cols[0]);
    	}
    }
    else if(SZ(rows) == 2){
    	assert(SZ(cols) == 0);
    	int l = 0, r = n;
    	while(l + 1 < r){
    		int m = (l + r) >> 1;
    		if(q(rows[0], 1, rows[0], m)){
    			r = m;
    		}
    		else{
    			l = m;
    		}
    	}
    	print(rows[0], r, rows[1], r);
    }
    else{
    	assert(SZ(rows) == 0);
    	int l = 0, r = n;
    	while(l + 1 < r){
    		int m = (l + r) >> 1;
    		if(q(1, cols[0], m, cols[0])){
    			r = m;
    		}
    		else{
    			l = m;
    		}
    	}
    	print(r, cols[0], r, cols[1]);
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