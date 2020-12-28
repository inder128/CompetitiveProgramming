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
    int n, m; cin>>n>>m;
    vector <vector <bool>> mat(n, vector <bool>(m));
    for (int i = 0; i < n; ++i){
    	string str; cin>>str;
    	for (int j = 0; j < m; ++j){
    		mat[i][j] = (str[j] == '1');
    	}
    }

    set <int> sxs;
    for (int i = 0; i + 1 < n; i += 2){
    	sxs.insert(i);
    }

    sxs.insert(n - 2);

    vector <pi> p1, p2, p3;
    for(int sx : sxs){
    	for (int j = 0; j < m - 2; ++j){
    		if(mat[sx][j] == false and mat[sx + 1][j] == false) continue;
    		else if(mat[sx][j] == true and mat[sx + 1][j] == false){
    			p1.pb({sx, j}); mat[sx][j] = !mat[sx][j];
    			p2.pb({sx, j + 1}); mat[sx][j + 1] = !mat[sx][j + 1];
    			p3.pb({sx + 1, j + 1}); mat[sx + 1][j + 1] = !mat[sx + 1][j + 1];

    		}
    		else if(mat[sx][j] == false and mat[sx + 1][j] == true){
    			p1.pb({sx + 1, j}); mat[sx + 1][j] = !mat[sx + 1][j];
    			p2.pb({sx, j + 1}); mat[sx][j + 1] = !mat[sx][j + 1];
    			p3.pb({sx + 1, j + 1}); mat[sx + 1][j + 1] = !mat[sx + 1][j + 1];
    		}
    		else{
    			p1.pb({sx, j}); mat[sx][j] = !mat[sx][j];
    			p2.pb({sx + 1, j}); mat[sx + 1][j] = !mat[sx + 1][j];
    			p3.pb({sx, j + 1}); mat[sx][j + 1] = !mat[sx][j + 1];
    		}
    	}
    }

    for (int sx = 0; sx + 1 < n; ++sx){
    	int j = m - 2;
    	if(mat[sx][j] == false and mat[sx][j + 1] == false) continue;
		else if(mat[sx][j] == true and mat[sx][j + 1] == false){
			p1.pb({sx, j}); mat[sx][j] = !mat[sx][j];
			p2.pb({sx + 1, j}); mat[sx + 1][j] = !mat[sx + 1][j];
			p3.pb({sx + 1, j + 1}); mat[sx + 1][j + 1] = !mat[sx + 1][j + 1];

		}
		else if(mat[sx][j] == false and mat[sx][j + 1] == true){
			p1.pb({sx, j + 1}); mat[sx][j + 1] = !mat[sx][j + 1];
			p2.pb({sx + 1, j}); mat[sx + 1][j] = !mat[sx + 1][j];
			p3.pb({sx + 1, j + 1}); mat[sx + 1][j + 1] = !mat[sx + 1][j + 1];

		}
		else{
			p1.pb({sx, j}); mat[sx][j] = !mat[sx][j];
			p2.pb({sx, j + 1}); mat[sx][j + 1] = !mat[sx][j + 1];
			p3.pb({sx + 1, j + 1}); mat[sx + 1][j + 1] = !mat[sx + 1][j + 1];
		}
    }


    if(mat[n - 1][m - 1] == true and mat[n - 1][m - 2] == false){
		p1.pb({n - 1, m - 1}); mat[n - 1][m - 1] = !mat[n - 1][m - 1];
		p2.pb({n - 2, m - 2}); mat[n - 2][m - 2] = !mat[n - 2][m - 2];
		p3.pb({n - 2, m - 1}); mat[n - 2][m - 1] = !mat[n - 2][m - 1];

	}
	if(mat[n - 1][m - 1] == false and mat[n - 1][m - 2] == true){
		p1.pb({n - 1, m - 2}); mat[n - 1][m - 2] = !mat[n - 1][m - 2];
		p2.pb({n - 2, m - 2}); mat[n - 2][m - 2] = !mat[n - 2][m - 2];
		p3.pb({n - 2, m - 1}); mat[n - 2][m - 1] = !mat[n - 2][m - 1];
	}
	

	vector <pi> eee = {{n - 2, m - 2}, {n - 2, m - 1}, {n - 1, m - 2}, {n - 1, m - 1}};

	vector <pi> e1, e0;
	for (pi p : eee){
		if(mat[p.F][p.S]){
			e1.pb(p);
		}
		else{
			e0.pb(p);
		}
	}


	if(e1.size()){
		p1.pb(e0[0]); mat[e0[0].F][e0[0].S] = !mat[e0[0].F][e0[0].S];
		p2.pb(e0[1]); mat[e0[1].F][e0[1].S] = !mat[e0[1].F][e0[1].S];
		p3.pb(e1[0]); mat[e1[0].F][e1[0].S] = !mat[e1[0].F][e1[0].S];

		p1.pb(e0[0]); mat[e0[0].F][e0[0].S] = !mat[e0[0].F][e0[0].S];
		p2.pb(e0[1]); mat[e0[1].F][e0[1].S] = !mat[e0[1].F][e0[1].S];
		p3.pb(e1[1]); mat[e1[1].F][e1[1].S] = !mat[e1[1].F][e1[1].S];
	}

	cout<<p1.size()<<el;
	for (int i = 0; i < p1.size(); ++i){
		cout<<p1[i].F + 1<<" "<<p1[i].S + 1<<" ";
		cout<<p2[i].F + 1<<" "<<p2[i].S + 1<<" ";
		cout<<p3[i].F + 1<<" "<<p3[i].S + 1<<" ";
		cout<<el;
	}


	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cout<<(mat[i][j]);
		}
		cout<<el;
	}
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}