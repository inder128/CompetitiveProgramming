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
    int n; cin>>n;
    vi len(n), tarr;
    vi arr[n];
    for (int i = 0; i < n; ++i){
    	cin>>len[i];
    	for (int j = 0; j < len[i]; ++j){
    		int x; cin>>x;
    		tarr.pb(x);
    		arr[i].pb(x);
    	}
    	sort(rng(arr[i]));
    }
    sort(rng(tarr));

    if(n==1 and len[0]==2){
    	cout<<max(arr[0][0], arr[0][1]) - min(arr[0][0], arr[0][1])<<" 2\n";
    	return;
    }


    int l = 0, r = tarr.size() - 1, tmx = INT_MAX, tmn = 0;
    while(l <= r){
    	int m = (l + r)>>1, mx = tarr[m], mn = tarr[m];

    	for (int i = 0; i < n; ++i){
    		vi tmp;
    		for (int j = 0; j < len[i]; ++j){
    			tmp.pb(abs(arr[i][j] - tarr[m]));
    		}
    		sort(rng(tmp));
    		int ch = (len[i] + 1)/2;
    		int diff = tmp[ch - 1];
    		// db(i, diff);
    		if(count(rng(arr[i]), tarr[m] - diff))
    			mini(mn, tarr[m] - diff);
    		else
    			maxi(mx, tarr[m] + diff);
    	}

    	if(mx - mn < tmx - tmn){
    		tmx = mx, tmn = mn;
    		// db(m, mn, mx, tarr[m]);
    	}

    	if(mx - tarr[m] > tarr[m] - mn){
    		l = m + 1;
    	}
    	else{
    		r = m - 1;
    	}
    }

    cout<<tmx - tmn<<" ";
    // db(tmx, tmn);

 	int cnt = 0;
 	for (int i : tarr){
 		if(i >= tmn and i <= tmx) cnt++;
 	}
 	cout<<cnt<<el;
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