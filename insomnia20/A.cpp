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


// this is wrong submission
const int N = 1e5;
vi len(N), req(N), isInc(N);
int ninc = 0, diff = INT_MAX, nd = 0, n;

set <pi> pnts;

void insert(){
	if(ninc < n) return;

	while(true){
		if(diff > pnts.rbegin()->F - pnts.begin()->F){
			diff = pnts.rbegin()->F - pnts.begin()->F;
			nd = pnts.size();
		}
		else if(diff == pnts.rbegin()->F - pnts.begin()->F){
			nd = max(nd, (int)pnts.size());
		}
		auto pt = *pnts.begin();
		pnts.erase(pt);
		isInc[pt.S]--;
		if(isInc[pt.S] < req[pt.S]){
			ninc--;
			break;
		}
	}
}

void solve(){
    cin>>n;
    vector <pi> tarr;
    for (int i = 0; i < n; ++i){
    	cin>>len[i];
    	req[i] = (len[i] + 1)/2;
    	for (int j = 0; j < len[i]; ++j){
    		int x; cin>>x;
    		tarr.pb({x, i});
    	}
    }

    if(n==1 and len[0]==2){
    	cout<<max(tarr[0].F, tarr[0].S) - min(tarr[0].F, tarr[0].S)<<" 2\n";
    	return;
    }

    sort(rng(tarr));

    for (int i = 0; i < tarr.size(); ++i){
    	isInc[tarr[i].S]++;
		if(isInc[tarr[i].S] == req[tarr[i].S]){
			ninc++;
		}
		pnts.insert(tarr[i]);

		if(i and (i==tarr.size()-1 or tarr[i].F < tarr[i+1].F)){
			// db(i, tarr[i].F);
			insert();
		}
    }

    cout<<diff<<" "<<nd<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}