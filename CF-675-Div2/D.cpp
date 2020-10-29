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

// nice question on dijkstra;
// in every movement from one station to another will be to nearest statoin to the (left or right or up or down);
// movement to any other station can be achieved by these operations in greater of equal cost;
// so the most optimal path from starting pos to any other station will consist of only these steps;
// so graph will only consist of these edjes;
typedef pair <pi, int> ppi;

void solve(){
    int n, m; cin>>n>>m;
    int sx, sy, ex, ey; cin>>sx>>sy>>ex>>ey;
    vector <ppi> stat(m + 1);
    stat[0].F = {sx, sy};
    for (int i = 1; i <= m; ++i){
    	cin>>stat[i].F.F>>stat[i].F.S;
    	stat[i].S = i;
    }


    // building graph from coordinates;
    vi adj[m + 1];

   	sort(rng(stat), [&](const ppi &p1, const ppi &p2){
   		return p1.F.F < p2.F.F;
   	});
   	for (int i = 0; i <= m; ++i){
   		if(i - 1 >= 0) adj[stat[i].S].pb(stat[i - 1].S);
   		if(i + 1 <= m) adj[stat[i].S].pb(stat[i + 1].S);
   	}

   	sort(rng(stat), [&](const ppi &p1, const ppi &p2){
   		return p1.F.S < p2.F.S;
   	});
   	for (int i = 0; i <= m; ++i){
   		if(i - 1 >= 0) adj[stat[i].S].pb(stat[i - 1].S);
   		if(i + 1 <= m) adj[stat[i].S].pb(stat[i + 1].S);
   	}



   	// ordering the stations;
   	sort(rng(stat), [&](const ppi &p1, const ppi &p2){
   		return p1.S < p2.S;
   	});


   	// Dijkstra
   	vi rel(m + 1), toReach(m + 1, INT_MAX);
   	priority_queue<pi, vector <pi> , greater<pi>> PQ;
   	PQ.push({0, 0});
   	while(PQ.size()){
   		pi node = PQ.top(); PQ.pop();
   		if(rel[node.S]) continue;
   		rel[node.S] = true;
   		toReach[node.S] = node.F;
   		for(int ch : adj[node.S]){
   			int xc = abs(stat[node.S].F.F - stat[ch].F.F);
   			int yc = abs(stat[node.S].F.S - stat[ch].F.S);
   			if(toReach[node.S] + min(xc, yc) < toReach[ch]){
   				toReach[ch] = toReach[node.S] + min(xc, yc);
   				PQ.push({toReach[ch], ch});
   			}
   		}
   	}

   	// final cost;
   	int ans = INT_MAX;
   	for (int i = 0; i <= m; ++i){
   		int xc = abs(stat[i].F.F - ex);
   		int yc = abs(stat[i].F.S - ey);
   		mini(ans, toReach[i] + xc + yc);
   	}
   	cout<<ans<<el;
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