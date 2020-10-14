#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL inf = 1e15;

class Segtree{
  private:
    vector<pair<LL,LL> >tr;
  public:
    Segtree(int n) {
        tr.resize(4 * n + 10);
        for(auto & i : tr) i.first = i.second = inf;
    }
    void updata(int x, int p, int L, int R, pair<LL,LL>num) {
        if(L == R) {
            tr[x] = min(tr[x], num); return;
        }
        int M = (L + R) / 2;
        if(p <= M) updata(x << 1, p, L, M, num);
        else updata(x << 1 | 1, p, M + 1, R, num);
        tr[x] = min(tr[x << 1], tr[x << 1 | 1]);
    }
    pair<LL,LL> query(int x, int l, int r, int L, int R) {
        if(l <= L && R <= r) {
            return tr[x];
        }
        int M = (L + R) / 2;
        pair<LL,LL> ans = {inf,inf};
        if(l <= M) ans = min(ans, query(x << 1, l, r, L, M));
        if(r > M) ans = min(ans, query(x << 1 | 1, l, r, M + 1, R));
        return ans;
    }
};

struct Point {
    int x, y, id;
    bool operator <(const Point& m) const {
        if(x == m.x) return y < m.y;
        return x < m.x;
    }
};

struct edge {
    LL u, v, w;
    bool operator<(const edge& a) const {return w < a.w;}
};

LL Kruskal(vector<edge>& e, int n) {
    vector<int> bcj;
    bcj.resize(n);
    iota(bcj.begin(), bcj.end(), 0);
    sort(e.begin(), e.end());
    function<int(int)>gr=[&](int k) {
        return k == bcj[k]?k:bcj[k] = gr(bcj[k]);
    };
    LL ans = 0;
    int num = 0;
    for (auto& i : e) {
        int x = gr(i.u), y = gr(i.v);
        if (x != y) {
            bcj[x] = gr(y);
            ans += i.w;
            num++;
        }
        if (num == n - 1) break;
    }
    if (num == n - 1) return ans;
    else return -1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<Point>a(n);
    function<LL(Point, Point)>dis=[&](Point aa, Point bb) {
        return abs(aa.x - bb.x) + abs(aa.y - bb.y);
    };
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    vector<edge>e;
    for(int i = 0; i < 4; i++) {
        if(i == 1 || i == 3) {
            for(auto & j : a) swap(j.x, j.y);
        }
        else if(i == 2) {
            for(auto & j : a) j.x = -j.x;
        }
        sort(a.begin(), a.end());
        vector<LL>b;
        for(auto& j : a) {
            b.push_back(j.y - j.x);
        }
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(), b.end()),b.end());
        function<int(LL)>getid =[&](LL u) {
            return lower_bound(b.begin(), b.end(), u) - b.begin() + 1;
        };
        int sz = b.size();
        Segtree st(sz);
        for(int j = a.size() - 1; j >= 0; j--) {
            int p = getid(a[j].y - a[j].x);
            pair<LL,LL>ans = st.query(1, p, sz, 1, sz);
            if(ans.first != inf) {
                e.push_back({a[j].id, a[ans.second].id, dis(a[j], a[ans.second])});
            }
            st.updata(1, p, 1, sz, make_pair(a[j].x + a[j].y, j));
        }
    }
    cout << Kruskal(e, n) << '\n';
    return 0;
}
