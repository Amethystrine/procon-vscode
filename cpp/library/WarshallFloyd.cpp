
// 最短距離（ベルマンフォード）
#include<vector>
using namespace std;
typedef long long ll;

class WarshallFloyd {
public:
  WarshallFloyd(ll n) {
    size = n;
    dist.resize(n);
    for (ll i = 0; i < n; i++)
    {
      dist[i].resize(n);
      for (ll j = 0; j < n; j++) {
        dist[i][j] = 1e18;  // 適宜最大値はオーバーフローしない程度に適当に
      }
      dist[i][i] = 0;
    }
  }

  void GetWarshall() {
    for (ll k = 0; k < size; k++) {
      for (ll i = 0; i < size; i++) {
        for (ll j = 0; j < size; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  ll size;
  vector<vector<ll>> dist; //距離（自分で代入すること）
};
