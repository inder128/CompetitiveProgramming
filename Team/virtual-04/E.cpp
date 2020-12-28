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


const int N = 5e4;
vector <array <int, 3>> coords;
vector <bool> vis(N);
int n; 
string str = "wrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answerwrong answer";

bool check(int i, int j){
	i--, j--;
	if(vis[i] or vis[j]){
		return false;
	}

	vis[i] = vis[j] = true;

	int x = min(coords[i][0], coords[j][0]);
	int y = min(coords[i][1], coords[j][1]);
	int z = min(coords[i][2], coords[j][2]);

	int X = max(coords[i][0], coords[j][0]);
	int Y = max(coords[i][1], coords[j][1]);
	int Z = max(coords[i][2], coords[j][2]);

	for(int k = 0; k < n; ++k){
		if(vis[k]) continue;
		if(x <= coords[k][0] and coords[k][0] <= X and y <= coords[k][1] and coords[k][1] <= Y and z <= coords[k][2] and coords[k][2] <= Z){
			db(k);
			return false;
		}
	}
	return true;
}


void solve(){
   cin >> n;
    vi ans;
    map <int, vector<array <int, 3>>> rects;
    for(int i = 0; i < n; ++i){
    	int x, y, z; cin >> x >> y >> z;
    	rects[x].pb({y, z, i});
    	coords.pb({x, y, z});
    }
    vi gextra;
    for(auto& p : rects){
    	int x = p.F;
    	auto& recv = p.S;
    	map <int, vector <pi>> pnts;
    	for(auto& rec : recv){
    		pnts[rec[0]].pb({rec[1], rec[2]});
    	}
    	vi extra;
    	for(auto& pp : pnts){
    		int y = pp.F;
    		auto lnv = pp.S;
    		if(SZ(lnv) % 2){
    			extra.pb(lnv.back().S);
    			lnv.pop_back();
    		}
    		for(int i = 0; i < SZ(lnv); i += 2){
    			ans.pb(lnv[i].S);
    			ans.pb(lnv[i + 1].S);
    		}
    	}
    	if(SZ(extra) % 2){
    		gextra.pb(extra.back());
    		extra.pop_back();
    	}
    	for(int i = 0; i < SZ(extra); i += 2){
    		ans.pb(extra[i]);
    		ans.pb(extra[i + 1]);
    	}
    }
    for(int i = 0; i < SZ(gextra); i += 2){
    	ans.pb(gextra[i]);
    	ans.pb(gextra[i + 1]);
    }

    for(int i = 0; i < SZ(ans); i += 2){
    	cout << ans[i] + 1 << " " << ans[i + 1] + 1 << el;
    	if(check(ans[i] + 1, ans[i + 1] + 1) == false){
    		cout << str << el;
    		return;
    	}
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