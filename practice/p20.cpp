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

const ll mod = 1e9 + 7;
const int N = 1e7;
vl l(N), w(N), h(N);

//FacebookHackerCupRound1

void solve(){
    ll n, k; cin>>n>>k;
    for (int i = 0; i < k; ++i) cin>>l[i];
    ll al, bl, cl, dl; cin>>al>>bl>>cl>>dl;
    for (int i = 0; i < k; ++i) cin>>w[i];
    ll aw, bw, cw, dw; cin>>aw>>bw>>cw>>dw;
    for (int i = 0; i < k; ++i) cin>>h[i];
    ll ah, bh, ch, dh; cin>>ah>>bh>>ch>>dh;

    set <pair<pl, ll>> seg;
    seg.insert({{l[0], l[0] + w[0]}, 2*(w[0] + h[0])});
    ll peri = 2*(w[0] + h[0]), ans = peri;
    for (int i = 1; i < n; ++i){
        // db(peri, ans);

        if(i>=k){
            l.pb((al*l[i-2] + bl*l[i-1] + cl)%dl + 1);
            w.pb((aw*w[i-2] + bw*w[i-1] + cw)%dw + 1);
            h.pb((ah*h[i-2] + bh*h[i-1] + ch)%dh + 1);
        }
        ll st = l[i], ed = l[i] + w[i], tper = 0;

        // db(l[i], w[i], h[i]);

        auto itr = seg.lower_bound({{st, 0}, 0});
 
        if(itr != seg.begin()) itr--;
        if((itr->F).S < st) itr++;

        for(auto it = itr; it != seg.end(); it = seg.upper_bound(*it)){
            ll tst = (it->F).F, ted = (it->F).S;
            if(tst > ed) break;

            st = min(st, tst), ed = max(ed, ted);
            tper += (it->S) - 2*(ted - tst + h[i]);
            // db(tst, ted, (it->S), tper);
            peri -= (it->S);
            seg.erase(it);
        }

        tper += 2*(ed - st + h[i]);
        

        seg.insert({{st, ed}, tper});
        // db(ed, st, tper, peri);
        peri = (peri + tper) % mod;
        ans = (ans * peri) % mod;
    }
    cout<<ans<<el;
}

//perimetric_chapter_2_sample_input
 /Users/inder/Documents/Competitive-Programming/practice/p20 < /Users/inder/Documents/Competitive-Programming/perimetric_chapter_2_input.txt > /Users/inder/Documents/Competitive-Programming/output.txt
// /Users/inder/Documents/Competitive-Programming/FacebookHackerCupRound1/A < /Users/inder/Documents/Competitive-Programming/FacebookHackerCupRound1/asd.txt > /Users/inder/Documents/Competitive-Programming/FacebookHackerCupRound1/output.txt
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    while(T--){
        cout<<"Case #"<<tc<<": ";
        solve();
        tc++;
    }
    return 0; 
}