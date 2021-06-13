#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define ll long long
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

struct node{
    int sz;
    int c[2];
};

class BitTrie{
public :
    vector <node> trie;
    int D;
    BitTrie(int D_){
        // numbers should be less that (2 ^ D);
        // size of trie containing all elements less than (2 ^ D) will be (2 ^ (D + 1) - 1);
        D = D_;
        trie.pb({0, {-1, -1}});
    }

    void insert(string str){
        int curr = 0;
        for(int i = 0; i < D; ++i){
            if(trie[curr].c[str[i] - '0'] == -1){
                trie[curr].c[str[i] - '0'] = SZ(trie);
                trie.pb({0, {-1, -1}});
            }
            curr = trie[curr].c[str[i] - '0'];
            trie[curr].sz++;
        }
    }

    int get(int curr = 0){
        if(curr == -1){
            return 0;
        }
        
        return  max(0, trie[curr].sz - 1) + get(trie[curr].c[0]) + get(trie[curr].c[1]);
    }
};

void solve(){
    int n, m; cin >> n >> m;

    BitTrie bt(m);
    for(int i = 0; i < n; ++i){
        string str; cin >> str;
        bt.insert(str);
    }

    cout << n * m - bt.get() << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}