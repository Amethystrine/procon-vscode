// seg tree(sum)

#include<climits>
#include<vector>
using namespace std;
typedef long long ll;

class SegTree {
public:
  SegTree(ll s) {
    size = 1;
    while (size < s)
      size *= 2;
    data.assign(size * 2 - 1, 0); // def unit
  }

  // 0 indexed
  void update(ll k, ll var) {
    k += size - 1;
    data[k] += var; // def func
    while (k > 0) {
      k = (k - 1) / 2;
      data[k] += var; //def func
    }
  }

  ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = LLONG_MAX) {
    if (r == LLONG_MAX)
      r = size;
    if (r <= a || b <= l) return LLONG_MAX; //define unit

    if (a <= l && r <= b) return data[k];
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return vl + vr; // def func
  }

  // Todo : minRight
  // Todo : maxLeft

  ll size;
  vector<ll> data;
};
