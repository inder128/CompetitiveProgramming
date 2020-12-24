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

void solve(){
    int a, b, c, d; 
    cin>>a>>b>>c>>d;
    a--, b--;

    cout<<50<<" "<<50<<el;

    // b, c;
    vector <string> mat(25, string(50, 'A'));
    for(int i = 1; i < 25 and (b + c); i += 2){
    	for(int j = 1; j < 50 and (b + c); j += 2){
    		if(b){
    			mat[i][j] = 'B';
    			b--;
    		}
    		else{
    			mat[i][j] = 'C';
    			c--;
    		}
    	}
    }

    for(auto str : mat) cout<<str<<el;

    // a, d;
    mat = vector <string> (25, string(50, 'B'));
    for(int i = 1; i < 25 and (a + d); i += 2){
    	for(int j = 1; j < 50 and (a + d); j += 2){
    		if(a){
    			mat[i][j] = 'A';
    			a--;
    		}
    		else{
    			mat[i][j] = 'D';
    			d--;
    		}
    	}
    }

    for(auto str : mat) cout<<str<<el;
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