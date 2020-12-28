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

vvi moves;
vector <string> mat;
int n, m;
queue <pi> Q;

vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

bool isValid(int x, int y){
    return x >= 0 and x < n and y >= 0 and y < m and mat[x][y] == '.' and moves[x][y] == -1;
}

void dfs(int x, int y){
    for (int i = 0; i < 4; ++i){
        int nx = x + dx[i], ny = y + dy[i];
        if(!isValid(nx, ny)) continue;
        moves[nx][ny] = moves[x][y];
        Q.push({nx, ny});
        dfs(nx, ny);
    }
}


void solve(){
    cin>>n>>m;
    int sx, sy; cin>>sx>>sy; sx--; sy--;
    int ex, ey; cin>>ex>>ey; ex--; ey--;
    moves = vvi(n, vi(m, -1));
    mat = vector <string> (n);
    for(string &str : mat) cin>>str;

    moves[sx][sy] = 0;
    Q.push({sx, sy});
    dfs(sx, sy);

    while(!Q.empty()){
        int x = Q.front().F, y = Q.front().S; Q.pop();
        if(x == ex and y == ey) break;

        for (int xf = -2; xf <= 2; ++xf){
            for (int yf = -2; yf <= 2; ++yf){
                int nx = x + xf, ny = y + yf;
                if(!isValid(nx, ny)) continue;
                moves[nx][ny] = moves[x][y] + 1;
                Q.push({nx, ny});
                dfs(nx, ny);
            }
        }
    }

    cout<<moves[ex][ey]<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}