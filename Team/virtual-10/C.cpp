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
#define SZ(x) ((double)(x).size()) 
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
typedef pair<double,double> pi; typedef vector<double> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/


double ver(double d, double u, double x, double xp, double yp, double vx, double vy){
	if(vx == 0){
		if(xp == x){
			return -2;
		}
		return -1;
	}
	double t = (x - xp) / vx;
	if(t < 0){
		return -1;
	}
	double ny = yp + t * vy;
	if(ny > u or ny < d){
		return -1;
	}
	return t;
}


double hor(double l, double r, double y, double xp, double yp, double vx, double vy){
	if(vy == 0){
		if(yp == y){
			return -2;
		}
		return -1;
	}
	double t = (y - yp) / vy;
	if(t < 0){
		return -1;
	}
	double nx = xp + t * vx;
	if(nx > r or nx < l){
		return -1;
	}
	return t;
}


void solve(){
    double n; cin >> n; 
    double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    vi x(n), y(n), vx(n), vy(n);
    for(int i = 0; i < n; ++i){
    	cin >> x[i] >> y[i] >> vx[i] >> vy[i];
    }

    vi tin{0}, tout{1e9};
    for(int i = 0; i < n; ++i){
    	if(vx[i] == 0 and vy[i] == 0){
    		if(x[i] < x2 and x[i] > x1 and y[i] < y2 and y[i] > y1){
    			continue;
    		}
    		cout << -1 << el;
    		return;
    	}


    	vi t(4);
    	t[0] = ver(y1, y2, x1, x[i], y[i], vx[i], vy[i]);
    	t[1] = ver(y1, y2, x2, x[i], y[i], vx[i], vy[i]);
    	t[2] = hor(x1, x2, y1, x[i], y[i], vx[i], vy[i]);
    	t[3] = hor(x1, x2, y2, x[i], y[i], vx[i], vy[i]);
    	if(x[i] < x2 and x[i] > x1 and y[i] < y2 and y[i] > y1){
    		t.pb(0);
    	}
    	vi tt;
    	for(double ttt : t){
    		if(ttt != -1){
    			tt.pb(ttt);
    		}
    	}
    	sort(rng(tt));
    	if(SZ(tt) == 0 or tt[0] == -2){
    		cout << -1 << el;
    		return;
    	}

    	tin.pb(tt[0]);
    	tout.pb(tt.back());
    }

    sort(rng(tin));
    sort(rng(tout));
    if(tin.back() < tout[0]){
    	cout << setprecision(12) << fixed << tin.back() << el;
    }
    else{
    	cout << -1 << el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}