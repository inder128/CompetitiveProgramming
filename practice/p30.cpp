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

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int bf(string str){
    int n = str.length();
    set <string> strs;
    for (int i = 0; i < n; ++i){
        char bc = str.back();
        str.pop_back();
        str.insert(str.begin(), bc);
        strs.insert(str);
    }
    return strs.size();
}

bool solve(){
    string str; cin>>str;
    int bans = bf(str);
    int n = str.length();
    vi lst(26, -1);
    set <int> diffs[26];
    for (int i = 0; i < n; ++i){
        if(lst[str[i] - 'a'] != -1)
            diffs[str[i] - 'a'].insert(i - lst[str[i] - 'a']);
        lst[str[i] - 'a'] = i;
    }

    int lcm = -1;
    for (int i = 0; i < 26; ++i){
        if(diffs[i].size() == 0) continue;
        if(diffs[i].size() > 1) return n;
        int ld = *diffs[i].begin();
        if(lcm == -1) lcm = ld;
        else lcm = (lcm*ld)/gcd(lcm, ld);
    }
    return (n%lcm == 0 ? lcm : n)==bans;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        cout<<solve()<<el;
    }
    return 0; 
}