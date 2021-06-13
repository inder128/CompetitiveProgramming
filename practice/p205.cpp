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
    vector <string> mat(n); cin >> mat;
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < i; ++j){
    		if(mat[i][j] == mat[j][i]){
    			cout << "YES" << el;
    			for(int k = 0; k < m + 1; ++k){
    				if(k % 2){
    					cout << i + 1 << " ";
    				}
    				else{
    					cout << j + 1 << " ";
    				}
    			}
    			cout << el;
    			return;
    		}
    	}
    }

    if(m % 2){
    	cout << "YES" << el;
	    for(int i = 0; i < m + 1; ++i){
	    	if(i % 2){
				cout << 1 << " ";
			}
			else{
				cout << 2 << " ";
			}
	    }
	    cout << el;	
	    return;
    }

    for(int b = 0; b < n; ++b){
    	map <char, int> path;
    	for(int a = 0; a < n; ++a){
    		if(a == b){
    			continue;
    		}
    		char pth = mat[a][b];
    		if(path.find(pth) != path.end()){
    			int c = path[pth];
    			if(m / 2 % 2 == 0){
    				swap(a, c);
    			}
    			cout << "YES" << el;
    			for(int i = 0, j = 0; i < m + 1; ++i){
    				if(i == m / 2){
    					cout << b + 1 << " ";
    					continue;
    				}
    				if(j % 2 == 0){
    					cout << a + 1 << " ";
    				}
    				else{
    					cout << c + 1 << " ";
    				}
    				j++;
    			}
    			return;
    		}
    		path[mat[b][a]] = a;
    	}
    }

    cout << "NO" << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}