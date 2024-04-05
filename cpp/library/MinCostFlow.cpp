#include<vector>
#include<climits>
using namespace std;
typedef long long ll;

class MinCostFlow {
public:
  struct edge { ll to, cap, cost, rev; };

  MinCostFlow(ll n) {
    pnt = n;
    edges.resize(n);
    dist.resize(n);
    prevVert.resize(n);
    prevEdge.resize(n);
  }

  void addEdge(ll from, ll to, ll cap, ll cost) {
    edge eF = { to,cap,cost,edges[to].size() };
    edges[from].push_back(eF);
    edge eT = { from,0,-cost,edges[from].size() - 1 };
    edges[to].push_back(eT);
  }

  ll getMinCostFlow(ll s, ll g, ll flow) {
    ll res = 0;
    while (flow > 0) {
      dist.assign(pnt, LLONG_MAX);
      dist[s] = 0;
      bool update = true;

      // �ŒZ�o�H��T��
      while (update) {
        update = false;
        for (ll v = 0; v < pnt; v++) {
          if (dist[v] == LLONG_MAX)
            continue;
          for (ll i = 0; i < edges[v].size(); i++) {
            edge& e = edges[v][i];
            if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
              dist[e.to] = dist[v] + e.cost;
              prevVert[e.to] = v;
              prevEdge[e.to] = i;
              update = true;
            }
          }
        }
      }
      // �����Ȃ�
      if (dist[g] == LLONG_MAX) {
        return -1;
      }
      // �ŒZ�o�H�ɗ���
      ll d = flow;
      for (ll v = g; v != s; v = prevVert[v]) {
        d = min(d, edges[prevVert[v]][prevEdge[v]].cap);
      }
      flow -= d;
      res += d * dist[g];
      for (ll v = g; v != s; v = prevVert[v]) {
        edge& e = edges[prevVert[v]][prevEdge[v]];
        e.cap -= d;
        edges[v][e.rev].cap += d;
      }
    }
    return res;
  }

  ll pnt;
  vector<vector<edge>> edges;
  vector<ll> dist;
  vector<ll> prevVert;
  vector<ll> prevEdge;
};