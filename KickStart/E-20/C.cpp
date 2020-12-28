#include <bits/stdc++.h>
using namespace std;
 
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}"; }
    #define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " |"; __f(comma + 1, args...); }
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
 
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
 
/*-----------------------------Code begins----------------------------------*/

struct comp{
    bool operator() (pi p1, pi p2){
        return p1.F + p1.S < p2.F + p2.S;
    }
};

void solve(){
    int n; cin>>n;
    vi e(n), r(n);
    for (int i = 0; i < n; ++i){
    	cin>>e[i]>>r[i];
    }
    ll sm = accumulate(rng(e), 0ll);
    ll mx = sm, ttl = sm, del = 0;

    priority_queue <pi, vector <pi>, comp> PQ;
    for (int i = 0; i < n; ++i){
    	PQ.push({e[i], r[i]});
    	sm += e[i];
    	while(!PQ.empty()){
    		pi tp = PQ.top();
    		if(ttl - tp.F < tp.S){
    			ttl -= tp.F;
    			sm -= 2*tp.F;
    			PQ.pop();
    		}else break;
    	}
    	if(sm > mx){
    		mx = sm;
    		del = (i + 1) - PQ.size();
    	}
    }

    if(!PQ.empty()){
    	cout<<n - PQ.size()<<" INDEFINITELY"<<el;
    }
    else{
    	cout<<del<<" "<<mx<<el;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    while(T--){
    	cout<<"Case #"<<tc<<": ";
        tc++;
        solve();
    }
    return 0; 
}