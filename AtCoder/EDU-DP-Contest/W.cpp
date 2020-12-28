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

// nice question;
// mix of DP and range update seg tree;
// make sure to make inc variable ll;
// check another ac submission;
const int N = 2e5 + 2;
vl ST(1<<19), lazy(1<<19);
int n, m;

void increase(int si, int ss, int se, ll inc){
	lazy[si] += inc;
	ST[si] += inc;
}

void shift(int si, int ss, int se){
	int mid = (ss+se)/2;
	increase(si*2 + 1, ss, mid, lazy[si]);
	increase(si*2 + 2, mid+1, se, lazy[si]);
	lazy[si] = 0;
}

void increaseUtil(int si, int ss, int se, int qs, int qe, ll inc){
	if (se < qs || ss > qe) return;

	if (qs <= ss && qe >= se) return increase(si, ss, se, inc); 

	shift(si, ss, se);
	int mid = (ss+se)/2;
	increaseUtil(2*si + 1, ss, mid, qs, qe, inc);
	increaseUtil(2*si + 2, mid+1, se, qs, qe, inc);
	ST[si] = min(ST[si*2 + 1], ST[si*2 + 2]);
}

void increase(int qs, int qe, ll inc){
	return increaseUtil(0, 0, n, qs, qe, inc);
}

ll getMinUtil(int si, int ss, int se, int qs, int qe) { 
	if(qs == ss and qe == se){
		return ST[si];
	}

	shift(si, ss, se);
	int mid = (ss + se)/2;

	if(qe <= mid) 
		return getMinUtil(2*si + 1, ss, mid, qs, qe);
	if(qs > mid)
		return getMinUtil(2*si + 2, mid + 1, se, qs, qe);

	return min(getMinUtil(2*si + 1, ss, mid, qs, mid), 
			getMinUtil(2*si + 2, mid + 1, se, mid + 1, qe));
}

ll getMin(int qs, int qe){
	return getMinUtil(0, 0, n, qs, qe);
}

void solve(){
    cin>>n>>m;
    vl DP(n + 2);
    vector <pi> ends[n + 2];
    ll totScore = 0;
    for (int i = 0; i < m; ++i){
    	int l, r, c; cin>>l>>r>>c;
    	ends[r].pb({l, c});
    	totScore += c;
    }

    for (int i = 1; i <= n + 1; ++i){
    	DP[i] = getMin(0, i - 1);
    	increase(i, i, DP[i]);
    	for(pi srt : ends[i]){
    		increase(0, srt.F - 1, srt.S);
    	}
    }
    //DP[i] = min score (sum of scores of untaken intervals) if str[i] = '1'; 

    //ans = total score - DP[n + 1];
    cout<<totScore - DP[n + 1]<<el;
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