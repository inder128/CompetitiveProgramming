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

// nice problem;
// check wrong soln in D.cpp;
// nice editorial;

int cost(int l, int gp){
	return (l%gp)*(l/gp + 1)*(l/gp + 1) + (gp - l%gp)*(l/gp)*(l/gp);
}

struct comp{
	bool operator()(const pi &p1, const pi &p2){
		return cost(p1.F, p1.S) - cost(p1.F, p1.S + 1) < cost(p2.F, p2.S) - cost(p2.F, p2.S + 1);
	}
};

void solve(){
    int n, k; cin>>n>>k;

    priority_queue <pi, vector <pi>, comp> PQ;
    int ans = 0;
    for (int i = 0; i < n; ++i){
    	int l; cin>>l;
    	ans += l*l;
    	PQ.push({l, 1});
    }

    k -= n;
    while(k--){
    	pi tp = PQ.top(); PQ.pop();
    	ans -= cost(tp.F, tp.S) - cost(tp.F, tp.S + 1);
    	PQ.push({tp.F, tp.S + 1});
    }

    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}