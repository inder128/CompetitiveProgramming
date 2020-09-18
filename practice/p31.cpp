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
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; 
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// codeforces link :-
// https://codeforces.com/problemset/problem/1288/E
// queries to find no. of distinct values in a subarray;

const int N = 3e5;
vi fr(N), fs(N);

int get(int pos, vi &f) {
	int res = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
	    res += f[pos];
	return res;
}
void update(int pos, int val, vi &f){
	for (; pos < int(f.size()); pos |= pos + 1)
		f[pos] += val;
}

void solve(){
    int n, m; cin>>n>>m;
    vi qry(m), lastPos(n, -1), mxPos(n);
    for(int &i : qry) cin>>i, i--;
    iota(rng(mxPos), 0);

    for (int i = 0; i < m; ++i){
    	if(lastPos[qry[i]] == -1){
    		update(qry[i], 1, fs);
    		mxPos[qry[i]] = max(mxPos[qry[i]], qry[i] + get(n-1, fs) - get(qry[i], fs));
    	}
    	else{
    		update(lastPos[qry[i]], -1, fr);
    		mxPos[qry[i]] = max(mxPos[qry[i]], get(i-1, fr) - get(lastPos[qry[i]], fr));
    	}
    	update(i, 1, fr);
    	lastPos[qry[i]] = i;
    }

    for (int i = 0; i < n; ++i){
    	if(lastPos[i] == -1)
			mxPos[i] = max(mxPos[i], i + get(n-1, fs) - get(i, fs));
		else
			mxPos[i] = max(mxPos[i], get(m-1, fr) - get(lastPos[i], fr));
		cout<<(lastPos[i] != -1 ? 1 : i+1)<<" "<<mxPos[i]+1<<el;  	
    }
}


// solution 2;
vi f;

void solve2(){
    int n, m; cin>>n>>m;
    f = vi(n+m);
    vi qry(m), mxPos(n), pos(n);
    for(int &i : qry) cin>>i, i--;
    iota(rng(mxPos), 0);
    for (int i = 0; i < n; ++i){
    	update(i, 1, f);
    	pos[i] = n-1-i;
    }

    for (int i = 0; i < m; ++i){
    	mxPos[qry[i]] = max(mxPos[qry[i]], get(n+i-1, f) - get(pos[qry[i]], f));
    	update(pos[qry[i]], -1, f);
    	update(n+i, 1, f);
    	pos[qry[i]] = n+i;
    }

    for (int i = 0; i < n; ++i){
    	mxPos[i] = max(mxPos[i], get(n+m-1, f) - get(pos[i], f));
		cout<<(pos[i] != n-1-i ? 1 : i+1)<<" "<<mxPos[i]+1<<el;  	
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        // solve();
        solve2();
    }
    return 0; 
}