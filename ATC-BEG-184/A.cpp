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
    int sx, sy; cin>>sx>>sy;
    int ex, ey; cin>>ex>>ey;
    if(sx == ex and ey == sy){
    	cout<<0<<el;
    	return;
    }
    if(sx + sy == ex + ey){
    	cout<<1<<el;
    	return;
    }
    if(sx - sy == ex - ey){
    	cout<<1<<el;
    	return;
    }
    int dx = abs(sx - ex);
    int dy = abs(sy - ey);
    if(dx + dy <= 3){
    	cout<<1<<el;
    	return;
    }

    if(abs(dx - dy) <= 3){
    	cout<<2<<el;
    	return;
    }

    // if(dx + dy <= 6){
    // 	cout<<2<<el;
    // 	return;
    // }

    if(dx%2 == dy%2){
    	cout<<2<<el;
    	return;
    }

    cout<<3<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}