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

vector <pi> pnts{{-2, 1}, {3, -1}, {-2, -1}, {1, -2}, {0, 3}, {2, 2}};

double len(int i, int j){
	int dx = pnts[i].F - pnts[j].F, dy = pnts[i].S - pnts[j].F;
	return sqrt(dx * dx + dy * dy);
}

double area(int i, int j, int k){
	i--, j--, k--;
	double a = len(i, j);
	double b = len(i, k);
	double c = len(j, k);
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int sgnn(int i, int j, int k){
	i--, j--, k--;
	int xa = pnts[j].F - pnts[i].F;
	int ya = pnts[j].S - pnts[i].S;
	int xb = pnts[k].F - pnts[i].F;
	int yb = pnts[k].S - pnts[i].S;
	return xa * yb - ya * xb > 0 ? 1 : -1;
}

double q1(int i, int j, int k){
	cout << 1 << " " << i << " " << j << " " << k << endl;
	double h; cin >> h;
	// double h = area(i, j, k); db(h);
	return h;
}

bool q2(int i, int j, int k){
	cout << 2 << " " << i << " " << j << " " << k << endl;
	int sgn; cin >> sgn;
	// int sgn = sgnn(i, j, k); db(sgn);
	return sgn == 1;
}


void get(vi& pos, vi& a, vi& b){
	int n = SZ(pos);
	if(n == 0){
		return;
	}

	// n > 0;
	vector <pair <double, int>> hn;
    for(int i : pos){
    	hn.pb({q1(1, 2, i), i});
    }
    sort(rng(hn));

    int l = hn[n - 1].S;
    for(int j = 0; j < n - 1; ++j){
    	auto [x, i] = hn[j];
    	if(q2(1, l, i)){
    		a.pb(i);
    	}
    	else{
    		b.pb(i);
    	}
    }
    a.pb(l);
}


void solve(){
    int n; cin >> n;
    vi pos, negs; // 1 ------> 2;
    for(int i = 3; i <= n; ++i){
    	if(q2(1, 2, i)){
    		pos.pb(i);
    	}
    	else{
    		negs.pb(i);
    	}
    }
    // db(pos, negs);

    vi a, b;
    get(pos, a, b);

    vi c, d; 
    get(negs, d, c);
    
    // 1 c d 2 b a;
    vi ans;
    ans.pb(1);
    ans.insert(ans.end(), rng(c));
    reverse(rng(d));
    ans.insert(ans.end(), rng(d));
    ans.pb(2);
    ans.insert(ans.end(), rng(b));
    reverse(rng(a));
    ans.insert(ans.end(), rng(a));

    if(q2(ans[0], ans[1], ans[2]) == false){
    	reverse(ans.begin() + 1, ans.end());
    }

    cout << 0 << " ";
    for(int i : ans){
    	cout << i << " ";
    }
    cout << endl;
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