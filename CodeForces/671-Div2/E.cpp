#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
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

void solve(){
    int n, tn; cin>>n;
    vector <int> pdivs;
    tn = n;
    for (ll i = 2; i*i <= tn; ++i){
    	if(tn%i) continue;
    	pdivs.pb(i);
    	while(tn%i == 0) tn /= i;
    }
    if(tn > 1) pdivs.pb(tn);
    int pn = pdivs.size();

    

    set <int> divs;
    for (ll i = 2; i*i <= n; ++i){
    	if(n%i) continue;
    	divs.insert(i);
    	divs.insert(n/i);
    }
    divs.insert(n);

    if(pn==1){
    	for(int d : divs) cout<<d<<" ";
    	cout<<el<<0<<el;
 		return;
    }
    if(pn==2){
    	if(pdivs[0]*pdivs[1] == n){
    		cout<<pdivs[0]<<" ";
    		cout<<pdivs[1]<<" ";
    		cout<<n<<"\n1\n";
    	}
    	else{
    		cout<<pdivs[0]<<" ";
    		set <int> ndels;
    		for(int d : divs){
    			if(d==n or d==pdivs[0] or d==pdivs[1] or d==pdivs[0]*pdivs[1]) continue;
    			else if(d%pdivs[0] == 0) cout<<d<<" ";
    			else ndels.insert(d);
    		}
    		cout<<pdivs[0]*pdivs[1]<<" ";
    		cout<<pdivs[1]<<" ";
    		for(int d : ndels) cout<<d<<" ";
    		cout<<n<<" ";
    		cout<<el<<0<<el;
    	}
    	return;
    }

    for (int i = 0; i < pn; ++i){
    	divs.erase(pdivs[i]);
    	divs.erase(pdivs[i]*pdivs[(i+1)%pn]);
    }
    for (int i = 0; i < pn; ++i){
    	cout<<pdivs[i]<<" ";

    	set <int> dels;
    	for(int d : divs){
    		if(d%pdivs[i]) continue;
    		cout<<d<<" ";
    		dels.insert(d);
    	}
    	for(int d : dels) divs.erase(d);

    	cout<<pdivs[i]*pdivs[(i+1)%pn]<<" ";
    }
    cout<<el<<0<<el;
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