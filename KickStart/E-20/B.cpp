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

void solve(){
    int n, a, b, c; cin>>n>>a>>b>>c;
    if(n - a - b + c < 0){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    if(n==1){
        cout<<"1\n";
        return;
    }
    if(n==2 and c==2){
        cout<<"1 1\n";
        return;
    }
    if(n==2 and a==2){
        cout<<"1 2\n";
        return;
    }
    if(n==2 and b==2){
        cout<<"2 1\n";
        return;
    }
    string ans;
    if(c > 1){
        ans.insert(ans.end(), a - c, '1');
        ans.insert(ans.end(), c - 1, '2');
        ans.insert(ans.end(), n - a - b + c, '1');
        ans.insert(ans.end(), 1, '2');
        ans.insert(ans.end(), b - c, '1');
    }
    else{
        if(a==1 and b==1){
            cout<<"IMPOSSIBLE\n";
            return;
        }
        if(a > 1){
            ans.insert(ans.end(), a - 1, '2');
            ans.insert(ans.end(), n - a - b + c, '1');
            ans.insert(ans.end(), 1, '3');
            ans.insert(ans.end(), b-1, '2');
        }
        else{
            ans.insert(ans.end(), a - 1, '2');
            ans.insert(ans.end(), 1, '3');
            ans.insert(ans.end(), n - a - b + c, '1');
            ans.insert(ans.end(), b - 1, '2');
        }
    }
    for(char c : ans) cout<<c<<" "; cout<<el;
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