#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
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
 
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
 
/*-----------------------------Code begins----------------------------------*/

// codeforces question link : -
// https://codeforces.com/contest/1263/problem/E

const int N = 1e6;
vi STmx(2*N), STmn(2*N), lazy(2*N);

void update(int si, int ss, int se, int inc){
    lazy[si] += inc;
    STmx[si] += inc;
    STmn[si] += inc;
}

void shift(int si, int ss, int se){
    int mid = (ss+se)/2;
    update(si*2+1, ss, mid, lazy[si]);
    update(si*2+2, mid+1, se, lazy[si]);
    lazy[si] = 0;
}

void increaseUtil(int si, int ss, int se, int qs, int qe, int inc){
    if (se < qs || ss > qe) return;

    if (qs <= ss && se <= qe) return update(si, ss, se, inc); 

    shift(si, ss, se);
    int mid = (ss+se)/2;
    increaseUtil(2*si+1, ss, mid, qs, qe, inc);
    increaseUtil(2*si+2, mid+1, se, qs, qe, inc);

    STmx[si] = max(STmx[si*2+1], STmx[si*2+2]);
    STmn[si] = min(STmn[si*2+1], STmn[si*2+2]);
}

void increase(int qs, int inc){
    return increaseUtil(0, 0, N-1, qs, N-1, inc);
}

void solve(){
    int n; cin>>n;
    string str; cin>>str;
    string pat(N, '$');
    int ptr = 0, sm = 0;
    for(char c : str){
        if(c == 'R') ptr++;
        else if(c == 'L'){
            if(ptr) ptr--;
        } 
        else{
            int add = 0;

            if(pat[ptr] == '(') add--;
            else if(pat[ptr] == ')') add++;
            
            if(c == '(') add++;
            else if(c == ')') add--;

            pat[ptr] = c;

            sm += add;

            increase(ptr, add);
        }

        // else if(c == '('){
        //     if(pat[ptr] == '('){
        //         // do nothing;
        //     }
        //     else if(pat[ptr] == '$'){
        //         sm++;
        //         increase(ptr, 1);
        //     }
        //     else{
        //         sm += 2;
        //         increase(ptr, 2);
        //     }
        //     pat[ptr] = '(';
        // }
        // else if(c == ')'){
        //     if(pat[ptr] == ')'){
        //         // do nothing;
        //     }
        //     else if(pat[ptr] == '$'){
        //         sm--;
        //         increase(ptr, -1);
        //     }
        //     else{
        //         sm -= 2;
        //         increase(ptr, -2);
        //     }
        //     pat[ptr] = ')';
        // }
        // else{
        //     if(pat[ptr] == '$'){
        //         // do nothing;
        //     }
        //     else if(pat[ptr] == '('){
        //         sm--;
        //         increase(ptr, -1);
        //     }
        //     else{
        //         sm++;
        //         increase(ptr,  1);
        //     }
        //     pat[ptr] = '$';
        // }


        if(STmn[0] < 0 or sm) cout<<-1<<" ";
        else cout<<STmx[0]<<" ";
    }
    cout<<el;
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