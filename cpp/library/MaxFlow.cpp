#ifdef false

//////�ő嗬
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;

class MaxFlow {
public:
  struct edge {
    ll to, cap, rev;
  };
  MaxFlow(ll n) {
    point = n;
    edges.resize(n);
    used.resize(n);
    minCut.resize(n);
  }
  void addEdge(ll from, ll to, ll cap, ll rev = 0) {
    edge eF = { to,cap - rev,edges[to].size() };
    edges[from].push_back(eF);
    edge eT = { from,rev,edges[from].size() - 1 };
    edges[to].push_back(eT);
  }

  ll dfs(ll v, ll t, ll f) {
    if (v == t)return f;
    used[v] = true;
    for (ll i = 0; i < edges[v].size(); i++) {
      edge& e = edges[v][i];
      if (!used[e.to] && e.cap > 0) {
        ll d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          edges[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  ll getMaxFlow(ll s, ll g) {
    ll flow = 0;
    for (;;) {
      used.assign(point, 0);
      ll f = dfs(s, g, LLONG_MAX);
      if (f == 0)break;
      flow += f;
    }
    return flow;
  }

  // after getMaxFlow. s Side is true
  void getMinCut(ll s) {
    minCut[s] = true;
    for (ll i = 0; i < edges[s].size(); i++) {
      edge& e = edges[s][i];
      if (!minCut[e.to] && e.cap > 0) {
        getMinCut(e.to);
      }
    }
  }

  ll point;
  vector<vector<edge>> edges;
  vector<bool> used;
  vector<bool> minCut;
};

#endif