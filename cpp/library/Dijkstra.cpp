
#include<vector>
using namespace std;
typedef long long ll;


// �_�C�N�X�g���@
#include<vector>
#include<climits>
#include<queue>
class Dijkstra {
public:
  struct edge { ll to, cost; };  // �s��,�e��,�t�e��,�R�X�g

  Dijkstra(ll n) {
    pnt = n;
    edges.resize(n);
    dist.resize(n);
    rev.resize(n);
  }
  // ---���F�L��---
  void addEdge(ll from, ll to, ll cost = 0) {
    edge eF = { to,cost };
    edges[from].push_back(eF);
  }


  void SetDefaultDist(ll s) {
    dist.assign(pnt, LLONG_MAX);
    dist[s] = 0;
    rev[s] = -1;

    que.push(P(0, s));
  }

  void CalcDist() {
    while (!que.empty()) {
      P p = que.top();
      que.pop();
      ll v = p.second;
      if (dist[v] < p.first)
        continue;
      for (ll i = 0; i < edges[v].size(); i++) {
        edge e = edges[v][i];
        if (dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          rev[e.to] = v;
          que.push(P(dist[e.to], e.to));
        }
      }
    }
  }

  void GetDist(ll s) {
    SetDefaultDist(s);
    CalcDist();
  }
  // ��{�f�[�^

  ll pnt;  // �_��
  typedef pair<ll, ll> P;
  priority_queue<P, vector<P>, greater<P>> que;
  vector<vector<edge>> edges;
  vector<ll> dist;
  vector<ll> rev;
};
