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

// c++ program to find shortest weighted
// cycle in undirected graph
# define INF 0x3f3f3f3f
struct Edge
{
    int u;
    int v;
    double weight;
    Edge(int uu, int vv, double weightw){
        u = uu,
        v = vv;
        weight = weightw;
    }
};

// weighted undirected Graph
class Graph
{
    int V ;
    list < pair <int, int > >*adj;

    // used to store all edge information
    vector < Edge > edge;

public :
    Graph( int V )
    {
        this->V = V ;
        adj = new list < pair <int, int > >[V];
    }

    void addEdge ( int u, int v, int w );
    void removeEdge( int u, int v, int w );
    double ShortestPath (int u, int v );
    void RemoveEdge( int u, int v );
    double FindMinimumCycle ();

};

//function add edge to graph
void Graph :: addEdge ( int u, int v, double w )
{
    adj[u].push_back( make_pair( v, w ));
    adj[v].push_back( make_pair( u, w ));

    // add Edge to edge list
    Edge e( u, v, w );
    edge.push_back ( e );
}

// function remove edge from undirected graph
void Graph :: removeEdge ( int u, int v, double w )
{
    adj[u].remove(make_pair( v, w ));
    adj[v].remove(make_pair(u, w ));
}

// find the shortest path from source to sink using
// Dijkstra’s shortest path algorithm [ Time complexity
// O(E logV )]
double Graph :: ShortestPath ( int u, int v )
{
    // Create a set to store vertices that are being
    // preprocessed
    set< pair<double, int> > setds;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<double> dist(V, INF);

    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, u));
    dist[u] = 0;

    /* Looping till all shortest distance are finalized
    then setds will become empty */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<double, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;

        // 'i' is used to get all adjacent vertices of
        // a vertex
        list< pair<int, double> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            double weight = (*i).second;

            // If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /* If the distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here. */
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    // return shortest path from current source to sink
    return dist[v] ;
}

// function return minimum weighted cycle
double Graph :: FindMinimumCycle ( )
{
    double min_cycle = INT_MAX;
    int E = edge.size();
    for ( int i = 0 ; i < E ; i++ )
    {
        // current Edge information
        Edge e = edge[i];

        // get current edge vertices which we currently
        // remove from graph and then find shortest path
        // between these two vertex using Dijkstra’s
        // shortest path algorithm .
        removeEdge( e.u, e.v, e.weight ) ;

        // minimum distance between these two vertices
        double distance = ShortestPath( e.u, e.v );

        // to make a cycle we have to add weight of
        // currently removed edge if this is the shortest
        // cycle then update min_cycle
        min_cycle = min( min_cycle, distance + e.weight );

        // add current edge back to the graph
        addEdge( e.u, e.v, e.weight );
    }

    // return shortest cycle
    return min_cycle ;
}

// driver program to test above function
void solve()
{
    int n; cin >> n;
    Graph g(n);

    vector <ll> x(n), y(n);



    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
        for(int j = 0; j < i; ++j){
            ll dot = x[i]*x[j] + y[i]*y[j];
            ll det = x[i]*y[j] - y[i]*x[j];
            double angle = atan2(det, dot);
            if(angle > 0)
            g.addEdge(i, j, sqrt((x[i] - x[j]) * 1ll * (x[i] - x[j]) + (y[i] - y[j]) * 1ll * (y[i] - y[j])));
        }
    }

    // making above shown graph
    // g.addEdge(0, 1, 4);


    

    cout << g.FindMinimumCycle() << endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    cin >> T;
    while(T--){
        cout << "Case #" << tc << ": ";
        tc++;
        solve();
    }
    return 0;
}