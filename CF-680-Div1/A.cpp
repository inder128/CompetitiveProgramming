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

int pow(int p, int q){
	int ans = 1;
	while(q--){
		ans *= p;
	}
	return ans;
}

void solve(){
    int p, q; cin>>p>>q;
    int op = p;
    vector <pi> facsq;
    for (int i = 2; i*i <= q and q > 1; ++i){
    	if(q % i) continue;
    	facsq.pb({i, 0});
    	while(q % i == 0){
    		facsq.back().S++;
    		q /= i;
    	}
    }
    if(q > 1) facsq.pb({q, 1});


    int div = LLONG_MAX;
    for(pi pr : facsq){
    	int pp = 0;
    	while(p % pr.F == 0){
    		p /= pr.F;
    		pp++;
    	}
    	if(pp < pr.S){
    		cout<<op<<el;
    		return;
    	}
    	else{
    		mini(div, pow(pr.F, pp - pr.S + 1));
    	}
    }

    cout<<op/div<<el;
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