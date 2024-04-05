
// �ŒZ�����i�x���}���t�H�[�h�j
#include<vector>
using namespace std;
typedef long long ll;

class BellmanFord {
public:
  struct edge { ll from, to, cost; };  // �s��,�e��,�t�e��,�R�X�g

  BellmanFord(ll n) {
    pnt = n;
    dist.resize(n);
  }
  void addEdge(ll from, ll to, ll cost = 1) {
    edge eF = { from,to,cost };
    edges.push_back(eF);
  }

  bool GetDist(ll s) {
    dist.assign(pnt, LLONG_MAX);
    dist[s] = 0;
    bool update = true;
    ll updateCount = 0;

    while (update) {
      update = false;
      for (ll ei = 0; ei < edges.size(); ei++) {
        edge e = edges[ei];
        if (dist[e.from] != LLONG_MAX && dist[e.to] > dist[e.from] + e.cost) {
          dist[e.to] = dist[e.from] + e.cost;
          update = true;
          if (updateCount++ > pnt * edges.size())
            return false;
        }
      }
    }
    return true;
  }

  bool FindNegativeLoop() {
    dist.assign(pnt, 0);
    for (ll i = 0; i < pnt; i++) {
      for (ll j = 0; j < edges.size(); j++) {
        edge e = edges[j];
        if (dist[e.from] != LLONG_MAX && dist[e.to] > dist[e.from] + e.cost) {
          dist[e.to] = dist[e.from] + e.cost;
          if (i == pnt - 1)
            return false;
        }
      }
    }
    return true;
  }


  ll pnt;
  vector<edge> edges;
  vector<ll> dist;
};

