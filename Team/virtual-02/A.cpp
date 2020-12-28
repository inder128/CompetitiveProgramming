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


map <char, char> inv = {{'<', 'v'}, {'v', '>'}, {'^', '<'}, {'>', '^'}, {'.', '.'}};

void rotate(vector <string>& mat, int n){
    for (int x = 0; x < n / 2; x++) { 
        for (int y = x; y < n - x - 1; y++) { 
            int temp = mat[x][y]; 
  
            mat[x][y] = mat[y][n - 1 - x]; 
  
            mat[y][n - 1 - x] = mat[n - 1 - x][n - 1 - y]; 
  
            mat[n - 1 - x][n - 1 - y] = mat[n - 1 - y][x]; 
  
            mat[n - 1 - y][x] = temp; 
        } 
    }
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < n; ++j){
    		mat[i][j] = inv[mat[i][j]];
    	}
    }
}


void solve(){
    int n; cin >> n;

    string op; cin >> op;
    int r = 0;
    for(char c : op){
    	if(c == 'L'){
    		r = (r + 1) % 4;
    	}
    	else{
    		r = (r - 1 + 4) % 4;
    	}
    }




    vector <string> mat(n);
    for(int i = 0; i < n; ++i){
    	cin >> mat[i];
    }

    for(int k = 0; k < r; ++k){
    	rotate(mat, n);
    }

    for(int i = 0; i < n; ++i){
    	cout << mat[i] << el;
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