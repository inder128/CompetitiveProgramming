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

const int N = 1e5 + 5;
vvi sparseTable(N, vi(20));
vi arr(N);

int getMax(int i, int j){
    return (arr[i] > arr[j] ? i : j);
}

int get(int l, int r){
    int len = r - l + 1;
    int p = floor(log2(len));
    return getMax(sparseTable[l][p], sparseTable[r - (1<<p) + 1][p]);
}

void solve(){
    int n, q; cin>>n>>q;
    for (int i = 0; i < n; ++i){
        cin>>arr[i];
    }
    vl cnt(n); for(ll &i : cnt) cin>>i;

    for (int i = 0; i < n; ++i)
        sparseTable[i][0] = i;
    for (int p = 1; p < 20; ++p)
        for (int i = 0; i <= n - (1<<p); ++i)
            sparseTable[i][p] = getMax(sparseTable[i][p-1], sparseTable[i + (1<<(p-1))][p-1]);

    while(q--){
        int op; cin>>op;
        if(op == 1){
            int l, r; cin>>l>>r;
            l--; r--;
            int mxi = get(l ,r);
            int qt; cin>>qt;
            cnt[mxi] += qt;
        }
        else{
            int v, i; cin>>v>>i;
            i--;
            int mxi = get(max(0, i - v), min(n-1, i + v));
            int qt, thr; cin>>qt>>thr;
            if(cnt[mxi] < thr or cnt[mxi] < qt){
                cout<<"No purchase\n";
            }
            else{
                cnt[mxi] -= qt;
                cout<<mxi + 1<<el;
            }
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