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

// Expected value -> bottom up appraoch

const int mxN = 51 + 1;
vi reqState(mxN);
int nd, f, k; 

map <vi, double> DP;

double get(vi state){
    if(state == reqState) return 0;
    if(DP.count(state)) return DP[state];

    int wc = 0; // wrong choices;
    for (int i = 0; i <= mxN-2; ++i){
        if(state[i+1] + 1 > reqState[i+1])
            wc += state[i] - state[i+1];
    }

    DP[state] = 1.0;
    vi nxtState = state;
    for (int i = 0; i <= mxN-2; ++i){
        if(state[i+1] + 1 > reqState[i+1]) continue;
        if(state[i] - state[i+1] == 0) continue;
        nxtState[i+1]++;
        DP[state] += ((1.0*(state[i] - state[i+1]))/f)*get(nxtState);
        nxtState[i+1]--;
    }
    DP[state] *= (1.0*f)/(f - wc);
    // db(state, DP[state]);
    return DP[state];
}

void solve(){
    DP.clear();
    fill(rng(reqState), 0);
    cin>>nd>>f>>k;

    for (int i = 0; i < k; ++i){
        int sz; cin>>sz;
        reqState[sz]++;
    } 
    reqState[0] = f - k;
    for (int i = mxN-2; i >= 0; --i){
        reqState[i] += reqState[i+1];
    }
    // db(reqState);

    vi st(mxN);
    st[0] = f;
    cout<<setprecision(6)<<fixed;
    cout<<get(st)<<el;
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