#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
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

// Nice problem :-
// https://codeforces.com/contest/1436/problem/E
// do not make variables with similar names (lastOcc and lastOccST);

/*
let lastOcc[i] be last occurence of i in arr till now;

lastOccST[v] represents some range {i, j};
lastOccST[v] = max(lastOcc[i], lastOcc[i + 1], ------ , lastOcc[j]);
basically arr[lastOcc[v] --- tillNow - 1] is the smallest suffix such that all the values from i to j are present in it.
*/

const int N = 1<<17;
vi lastOccST(2*N, -1);
int n;

// return the smallest i such that lastOcc[i] < pos;
int getMEXutil(int si, int ss, int se, int pos){
    // we have reached the answer;
    if(ss == se) return ss;

    int mid = (ss + se)/2;
    if(lastOccST[2*si + 1] < pos){
        // it means there is some element in [ss---mid] whose lastOcc is lesss than pos;
        return getMEXutil(2*si + 1, ss, mid, pos);
    }

    // it means there is no element in [ss---mid] whose lastOcc is lesss than pos;
    // every element in [ss---mid] is present after pos in the array;
    return getMEXutil(2*si + 2, mid + 1, se, pos);
}

int getMEX(int pos){
    return getMEXutil(0, 0, n, pos);
}

void updateUtil(int si, int ss, int se, int elem, int pos){
    if(ss == se){
        lastOccST[si] = pos;
        return;
    }

    int mid = (ss + se)/2;
    if(elem <= mid) updateUtil(2*si + 1, ss, mid, elem, pos);
    else updateUtil(2*si + 2, mid + 1, se, elem, pos);

    lastOccST[si] = min(lastOccST[2*si + 1], lastOccST[2*si + 2]);
}

void update(int elem, int pos){
    return updateUtil(0, 0, n, elem, pos);
}

void solve(){
    cin>>n;
    vi lastOcc(n + 1, -1);
    vb isMEX(n + 1);
    for (int i = 0; i < n; ++i){
        int elem; cin>>elem; elem--;
        if(lastOcc[elem] + 1 < i){
            int mex = getMEX(lastOcc[elem] + 1);
            isMEX[mex] = isMEX[mex] | (mex == elem);
        }
        update(elem, i);
        lastOcc[elem] = i;
    }

    for (int elem = 0; elem <= n; ++elem){
        if(lastOcc[elem] + 1 < n){
            int mex = getMEX(lastOcc[elem] + 1);
            isMEX[mex] = isMEX[mex] | (mex == elem);
        }
    }


    int i = 0;
    while(isMEX[i]) i++;
    cout<<i + 1<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}