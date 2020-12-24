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

// https://codeforces.com/contest/1392/problem/E
// check editorial;

void solve(){
	int n; cin>>n;
	// int n = 10;
    vvi mat(n, vi(n));
    vector <vector <pi>> lr(n, vector <pi>(n));
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < n; ++j){
    		if(i == 0){
    		}
    		else if(j == 0){
    			mat[i][j] = (1 << (i - 1));
    			lr[i][j] = {lr[i - 1][j].F + mat[i][j], lr[i - 1][j].S + mat[i][j]};
    		}
    		else{
    			mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
    			lr[i][j] = {lr[i - 1][j].F + mat[i][j], lr[i][j - 1].S + mat[i][j]};
    		}
    		cout<<mat[i][j]<<" ";
    	}
    	cout<<el;
    }
    cout<<endl;


    auto gen = [&](){
    	int cost = 0;
    	int i = 0, j = 0;
    	while(i < n - 1 or j < n - 1){
    		cost += mat[i][j];
    		cout<<i + 1<<" "<<j + 1<<"  ";
    		if(i == n - 1){
    			j++;
    		}
    		else if(j == n - 1){
    			i++;
    		}
    		else{
    			if(rand() % 2){
    				i++;
    			}
    			else{
    				j++;
    			}
    		}
    	}
    	cout<<n<<" "<<n<<el;
    	return cost + mat[n - 1][n - 1];
    };

    int q; cin>>q;
    while(q--){
    	int k; cin>>k;
    	// int k = gen();
    	int ci = n - 1, cj = n - 1;
    	vector <pi> path;
    	while(ci + cj){
    		path.pb({ci, cj});
    		k -= mat[ci][cj];
    		if(ci == 0){
    			cj--;
    		}
    		else if(cj == 0){
    			ci--;
    		}
    		else{	
    			if(k <= lr[ci - 1][cj].S){
    				ci--;
    			}
    			else{
    				cj--;
    			}
    		}
    	}
    	assert(k == 0);
    	path.pb({0, 0});
    	reverse(rng(path));
    	for(pi p : path){
    		cout<<p.F + 1<<" "<<p.S + 1<<el;
    	}
    	cout<<endl;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    srand(time(0));
    while(T--){
        solve();
    }
    return 0;
}