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

const int N = 5e5;
vvi trie(N, vi(26, -1));
vi ed(N), red(N);
int nxt = 1;

void build(string s, int ind){
    int i = 0, v = 0;
    for(char c : s){
        if(trie[v][c - 'a'] == -1)
            trie[v][c - 'a'] = nxt++;
        v = trie[v][c - 'a'];
    }
    // db(v, s);
    ed[v] = ind;
    red[ind] = v;
}

void prinMin(){
    int v = 0;
    while(true){
        int i;
        for (i = 0; i < 26; ++i){
            if(trie[v][i] != -1){
                // cout<<((char)('a' + i));
                v = trie[v][i];
                break;
            }
        }
        if(i == 26) break;
    }
    mnv = v;
}

void prinMax(){
    int v = 0;
    while(true){
        int i;
        for (i = 25; i >= 0; --i){
            if(trie[v][i] != -1){
                // cout<<((char)('a' + i));
                v = trie[v][i];
                break;
            }
        }
        if(i == -1) break;
    }
    mxv = v;
}

void clean(){
    for (int i = 0; i <= nxt; ++i){
        for (int j = 0; j < 26; ++j){
            trie[i][j] = -1;
        }
        ed[i] = red[i] = -1;
    }
    nxt = 1;
}

void solve(){

    clean();


    int n; cin>>n;
    for (int i = 0; i < n; ++i){
        string str; cin>>str;
        build(str, i+1);
    }
    for (int i = 0; i < 10; ++i){
        // db(trie[i]);
    }
    // db(ed, red);
    prinMin();
    prinMax();
    int q; cin>>q;
    while(q--){
        int op; cin>>op;
        if(op == 1){
            int id; cin>>id;
            char c; cin>>c;
            int v = red[id];
            if(trie[v][c - 'a'] == -1)
                trie[v][c - 'a'] = nxt++;
            int tv = trie[v][c - 'a'];
            if(v == mnv)
            n++;
            red[n] = tv;
            ed[tv] = n;
            // db(ed, tv);
        }
        else if(op == 2){
            cout<<ed[mnv]<<el;
        }
        else{
            cout<<ed[mnv]<<el;
        }
    }
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