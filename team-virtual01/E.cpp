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

vvi prems, ValidArr;
bool adj[120][120];
int n, nf;
vi perm, arr;


void calc(){
	if(SZ(arr) == n){
		ValidArr.pb(arr);
		return;
	}
	for(int j = 0; j < nf; ++j){
		int go = true;
		for(int k : arr){
			if(!adj[j][k]){
				go = false;
				break;
			}
		}
		if(go == false) continue;
		arr.pb(j);
		calc();
		arr.pop_back();
	}
}


int inc(vi v){
	int mx = 0, ans = 0;
	for(int i = 0; i < n; ++i){
		if(v[i] > mx){
			ans++;
			mx = v[i];
		}
	}
	return ans;
}


void solve(){
	prems.clear();
    perm.clear();

	cin >> n;

    for(int i = 0; i < n; ++i){
    	perm.pb(i + 1);
    }
    do{
    	prems.pb(perm);
    }while(next_permutation(rng(perm)));

    nf = SZ(prems);

    
    for(int i = 0; i < nf; ++i){
    	for(int j = 0; j < nf; ++j){
    		adj[i][j] = true;
    		for(int k = 0; k < n; ++k){
    			if(prems[i][k] == prems[j][k]){
    				adj[i][j] = false;
    			}
    		}
    	}
    }

    ValidArr.clear();
    arr.clear();

    calc();

    // db(SZ(prems));





    vvi act(n, vi(n));
    vi rowf(n), rowb(n), colf(n), colb(n);

    vector <string> mat(n + 2);
    for(auto &str : mat) cin >> str;
    for(int i = 1; i <= n; ++i){
    	for(int j = 1; j <= n; ++j){
    		if(mat[i][j] != '-'){
    			act[i - 1][j - 1] = mat[i][j] - '0';
    		}
    	}
    }
    for(int i = 1; i <= n; ++i){
    	if(mat[i][0] != '-'){
    		rowf[i - 1] = mat[i][0] - '0';
    	}
    	if(mat[i][n + 1] != '-'){
    		rowb[i - 1] = mat[i][n + 1] - '0';
    	}
    }
    for(int j = 1; j <= n; ++j){
    	if(mat[0][j] != '-'){
    		colf[j - 1] = mat[0][j] - '0';
    	}
    	if(mat[n + 1][j] != '-'){
    		colb[j - 1] = mat[n + 1][j] - '0';
    	}
    }




    

    for(vi arr : ValidArr){
    	vvi curr(n, vi(n));
    	for(int i = 0; i < n; ++i){
    		curr[i] = prems[arr[i]];
    	}
    	bool sol = true;
    	for(int i = 0; i < n and sol; ++i){
    		for(int j = 0; j < n and sol; ++j){
    			if(act[i][j] and act[i][j] != curr[i][j]){
    				sol = false;
    			}
    		}
    	}
 		if(sol == false){
    		continue;
    	}
    	for(int i = 0; i < n and sol; ++i){
    		if(rowf[i] == 0) continue;
    		if(inc(curr[i]) != rowf[i]){
    			sol = false;
    		}
    	}
    	if(sol == false){
    		continue;
    	}
    	for(int i = 0; i < n and sol; ++i){
    		if(rowb[i] == 0) continue;
    		reverse(rng(curr[i]));
    		if(inc(curr[i]) != rowb[i]){
    			sol = false;
    		}
    		reverse(rng(curr[i]));
    	}
    	if(sol == false){
    		continue;
    	}
    	for(int i = 0; i < n; ++i){
    		for(int j = i + 1; j < n; ++j){
    			swap(curr[i][j], curr[j][i]);
    		}
    	}
    	for(int j = 0; j < n and sol; ++j){
    		if(colf[j] == 0) continue;
    		if(inc(curr[j]) != colf[j]){
    			sol = false;
    		}
    	}
    	if(sol == false){
    		continue;
    	}
    	for(int j = 0; j < n and sol; ++j){
    		if(colb[j] == 0) continue;
    		reverse(rng(curr[j]));
    		if(inc(curr[j]) != colb[j]){
    			sol = false;
    		}
    		reverse(rng(curr[j]));
    	}
    	if(sol == false){
    		continue;
    	}
    	for(int i = 0; i < n; ++i){
    		for(int j = i + 1; j < n; ++j){
    			swap(curr[i][j], curr[j][i]);
    		}
    	}
    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < n; ++j){
    			cout << curr[i][j];
    		}
    		cout << el;
    	}
    	cout << el;
    	return;
    }
    cout << "no" << el << el;
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