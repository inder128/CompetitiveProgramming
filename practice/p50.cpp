#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<" : "<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// https://codeforces.com/problemset/problem/1327/D
// approx no of factors of n -> n^(1/3);

void solve(){
    int n; cin>>n;
    vi per(n), col(n), tmp;
    for(int &i : per) cin>>i, i--;
    for(int &i : col) cin>>i;
    vb vis(n);
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i){
        if(vis[i]) continue;
        vis[i] = true;
        tmp.clear();
        tmp.pb(col[i]);
        int j = per[i];
        while(j != i){
            vis[j] = true;
            tmp.pb(col[j]);
            j = per[j];
        }
        int sz = tmp.size();
        for (int div = 1; div <= sz; ++div){
        	if(sz%div) continue;
        	// div cycles;
        	bool isReq = false;
        	for (int cy = 0; cy < div; ++cy){
        		bool isReqCy = true;
        		for (int j = cy; j < sz; j += div){
        			if(tmp[j] != tmp[cy]){
        				isReqCy = false;
        				break;
        			}
        		}
        		isReq = isReqCy;
        		if(isReq) break;
        	}
        	if(isReq){
        		ans = min(ans, div);
        		break;
        	} 
        }
    }
    cout<<ans<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}