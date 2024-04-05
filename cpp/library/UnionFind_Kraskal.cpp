

///////////// Union Find
using namespace std;
typedef long long ll;
#include <vector>
#include <algorithm>
class UnionFind {
public:

  UnionFind(ll num) {
    parent.resize(num);
    size.resize(num);

    for (ll i = 0; i < num; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  ll GetRoot(ll leaf) {
    if (parent[leaf] == leaf) {
      return leaf;
    }
    return parent[leaf] = GetRoot(parent[leaf]);
  }

  void Union(ll a, ll b)
  {
    ll ra = GetRoot(a);
    ll rb = GetRoot(b);
    if (ra == rb) return;
    if (size[ra] < size[rb]) swap(ra, rb);
    size[ra] += size[rb];
    parent[rb] = ra;
  }

  bool SameUnion(ll a, ll b) {
    ll ra = GetRoot(a);
    ll rb = GetRoot(b);
    return ra == rb;
  }

  vector<ll> parent;
  vector<ll> size;   // only root
};

class Kruskal {
public:
  struct edge { ll u, v, cost; };

  Kruskal(ll n) {
    pnt = n;
  }

  static bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
  }

  void AddEdge(ll u, ll v, ll cost) {
    edges.push_back(edge{ u, v, cost });
  }

  ll GetMSTCost() {
    sort(edges.begin(), edges.end(),comp);
    UnionFind uf(pnt);
    ll res = 0;
    for (int i = 0; i < edges.size(); i++) {
      edge e = edges[i];
      if (!uf.SameUnion(e.u, e.v)) {
        uf.Union(e.u, e.v);
        res += e.cost;
      }
    }
    return res;
  }


  vector<edge> edges;
  ll pnt;
};