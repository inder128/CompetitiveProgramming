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

void solve(){
    int n, m; cin >> n >> m;
    vector <string> mat(n);
    for(int i = 0; i < n; ++i){
    	cin >> mat[i];
    }

    auto checkRow = [&](int r){
    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < m; ++j){
    			int i2;
    			if(i <= r){
    				i2 = r + r - i + 1;
    			}
    			else{
    				i2 = r - (i - r) + 1;
    			}
    			if(i2 < 0 or i2 >= n){
    				if(mat[i][j] == '.'){
    					return false;
    				}
    			}
    			else{
    				if(mat[i][j] == mat[i2][j]){
	    				return false;
	    			}
    			}
    		}
    	}

    	return true;
    };


    auto checkCol = [&](int c){
    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < m; ++j){
    			int j2;
    			if(j <= c){
    				j2 = c + c - j + 1;
    			}
    			else{
    				j2 = c - (j - c) + 1;
    			}
    			if(j2 < 0 or j2 >= m){
    				if(mat[i][j] == '.'){
    					return false;
    				}
    			}
    			else{
    				if(mat[i][j] == mat[i][j2]){
	    				return false;
	    			}
    			}
    		}
    	}
    	return true;
    };

    auto check = [&](int& r1, int& c1, int& r2, int& c2){
    	if(r1 > r2){
    		return false;
    	}
    	if(r1 == r2){
    		if(c1 == 0 and c2 == m - 1 and r1 < n - 1){
    			return checkRow(r1);
    		}
    		else{
    			return false;
    		}
    	}
    	if(c1 == c2){
    		if(r1 == 0 and r2 == n - 1 and c1 < m - 1){
    			return checkCol(c1);
    		}
    		else{
    			return false;
    		}
    	}
    	if(abs(r1 - r2) == abs(c1 - c2)){

    		if(r1 >= 1 and r1 <= n - 2 and c1 >= 1 and c1 <= m - 2){
    			return false;
    		}
    		if(r2 >= 1 and r2 <= n - 2 and c2 >= 1 and c2 <= m - 2){
    			return false;
    		}

    		// check diag;

    		int slope;
    		if(r1 == 0 and c1 == 0 and r2 == 0 and c2 == 0){
    			slope = 1;
    		}
    		else if(r1 == n - 1 and c1 == m - 1 and r2 == n - 1 and c2 == m - 1){
    			slope = 1;
    		}
    		else if(r1 == 0 and c1 == m - 1 and r2 == 0 and c2 == m - 1){
    			slope = -1;
    		}
    		else if(r1 == n - 1 and c1 == 0 and r2 == n - 1 and c2 == 0){
    			slope = -1;
    		}
    		else{
    			slope = (c1 - c2) / (r1 - r2);
    		}

    		int c = c1 - slope * r1;


    		for(int i = 0; i < n; ++i){
    			for(int j = 0; j < m; ++j){
    				if((c2 - j) * (i - r1) == (r2 - i) * (j - c1)){
    					if(mat[i][j] == '.'){
    						return false;
    					}
    					continue;
    				}

    				int i2 = slope * j - slope * c, j2 = slope * i + c;
    				assert((j2 - j) / (i2 - i) == -slope);

    				if(i2 >= 0 and i2 < n and j2 >= 0 and j2 < m){
		    			if(mat[i][j] == mat[i2][j2]){
		    				return false;
		    			}
		    		}
		    		else{
		    			if(mat[i][j] == '.'){
		    				return false;
		    			}
		    		}
    			}
    		}

    		if(slope == -1){
    			swap(r1, r2), swap(c1, c2);
    		}

    		return true;
    	}
    	return false;
    };

    for(int r1 = 0; r1 < n; ++r1){
    	for(int c1 = 0; c1 < m; ++c1){
    		for(int r2 = 0; r2 < n; ++r2){
    			for(int c2 = 0; c2 < m; ++c2){
    				if(check(r1, c1, r2, c2)){
    					cout << r1 + 1 << " " << c1 + 1 << " " << r2 + 1 << " " << c2 + 1 << el;
    					return;
    				}
    			}
    		}
    	}
    }
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