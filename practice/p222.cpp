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
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

// https://codeforces.com/contest/1492/problem/E

vvi mat;
int n, m;

bool get(int ch = 0){
	if(ch > 2){
		return false;
	}

	for(int i = 1; i < n; ++i){
		vi diffs;
    	for(int j = 0; j < m; ++j){
    		if(mat[i][j] !=mat[0][j]){
    			diffs.pb(j);
    		}
    	}
    	int df = SZ(diffs);
    	if(df <= 2){
    		continue;
    	}
    	if(df <= 4){
    		for(int p : diffs){
    			int val = mat[0][p];
    			mat[0][p] = mat[i][p];
    			if(get(ch + 1)){
    				return true;
    			}
    			mat[0][p] = val;
    		}
    	}
       	return false;
	}
	return true;
}

void solve(){
	cin >> n >> m;
    mat = vvi(n, vi(m)); cin >> mat;

    if(get()){
    	cout << "Yes" << el;
    	for(int i = 0; i < m; ++i){
    		cout << mat[0][i] << " ";
    	}
    	cout << el;
    }
    else{
    	cout << "No" << el;
    }
}

// wring solution;
void solve2(){
    cin >> n >> m;
    mat = vvi(n, vi(m)); cin >> mat;

    auto get = [&](vi arr){
    	for(int i = 0; i < n; ++i){
    		int df = 0;
    		for(int j = 0; j < m; ++j){
    			if(arr[j] != mat[i][j]){
    				df++;
    			}
    		}
    		if(df > 2){
    			return false;
    		}
    	}
    	cout << "Yes" << el;
    	for(int i = 0; i < m; ++i){
    		cout << arr[i] << " ";
    	}
    	cout << el;
    	return true;
    };

    /*
    mat = 
    a b c x1 x2 x3 d e f
    a b c y1 y2 y3 d e f
    a b c z1 z2 z3 d e f

    it will output "No"

    but ans should be = 
    a b c x1 y2 z3 d e f
    */

    for(int i = 1; i < n; ++i){
    	vi diffs;
    	for(int j = 0; j < m; ++j){
    		if(mat[i][j] !=mat[0][j]){
    			diffs.pb(j);
    		}
    	}
    	int df = SZ(diffs);
    	if(df <= 2){
    		continue;
    	}
    	if(df <= 4){
    		vi arr1 = mat[0], arr2 = mat[i];
    		for(int p1 = 0; p1 < df; ++p1){
    			for(int p2 = p1 + 1; p2 < df; ++p2){
    				swap(arr1[diffs[p1]], arr2[diffs[p1]]);
    				swap(arr1[diffs[p2]], arr2[diffs[p2]]);
    				if(get(arr1) or get(arr2)){
    					return;
    				}
    				swap(arr1[diffs[p1]], arr2[diffs[p1]]);
    				swap(arr1[diffs[p2]], arr2[diffs[p2]]);
    			}
    		}
    	}
    	cout << "No" << el;
       	return;
    }
    if(get(mat[0]) == false){
    	cout << "No" << el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}