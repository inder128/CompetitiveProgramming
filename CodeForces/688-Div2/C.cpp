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
	int n; cin>>n;
    vvi mat(n, vi(n));
    string str;
    for(int i = 0; i < n; ++i){
    	cin>>str;
    	for(int j = 0; j < n; ++j){
    		mat[i][j] = str[j] - '0';
    	}
    }

    vi hd(10, -1);
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < n; ++j){
    		hd[mat[i][j]] = i;
    	}
    }


    vi hu(10, -1);
    for(int i = n - 1; i >= 0; --i){
    	for(int j = 0; j < n; ++j){
    		hu[mat[i][j]] = i;
    	}
    }


    vi vl(10, -1);
    for(int j = n - 1; j >= 0; --j){
    	for(int i = 0; i < n; ++i){
    		vl[mat[i][j]] = j;
    	}
    }


    vi vr(10, -1);
    for(int j = 0; j < n; ++j){
    	for(int i = 0; i < n; ++i){
    		vr[mat[i][j]] = j;
    	}
    }







    vvi dc(n, vi(10, 0));
    for(int j = 0; j < n; ++j){
    	for(int i = 0; i < n; ++i){
    		dc[j][mat[i][j]] = i;
    	}
    }


    vvi uc(n, vi(10, n - 1));
    for(int j = 0; j < n; ++j){
    	for(int i = n - 1; i >= 0; --i){
    		uc[j][mat[i][j]] = i;
    	}
    }


    vvi lr(n, vi(10, n - 1));
    for(int i = 0; i < n; ++i){
    	for(int j = n - 1; j >= 0; --j){
    		lr[i][mat[i][j]] = j;
    	}
    }


    vvi rr(n, vi(10, 0));
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < n; ++j){
    		rr[i][mat[i][j]] = j;
    	}
    }





    vi ans(10, 0);

    for(int d = 0; d < 10; ++d){
    	if(vr[d] == -1) continue;
    	for(int j = 0; j < n; ++j){
    		int ln = max(dc[j][d] - 0, n - 1 - uc[j][d]);
    		int hgt = max(abs(j - vl[d]), abs(vr[d] - j));
    		maxi(ans[d], ln * hgt);
    	}
    }


    for(int d = 0; d < 10; ++d){
    	if(hu[d] == -1) continue;
    	for(int i = 0; i < n; ++i){
    		int ln = max(n - 1 - lr[i][d], rr[i][d] - 0);
    		int hgt = max(abs(i - hu[d]), abs(hd[d] - i));
    		maxi(ans[d], ln * hgt);
    	}
    }


    for(int i = 0; i < 10; ++i){
    	cout<<ans[i]<<" ";
    }
    cout<<el;


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