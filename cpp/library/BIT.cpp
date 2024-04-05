
#include<climits>
#include<vector>
using namespace std;
typedef long long ll;

template<typename T=ll>
class BIT {
public:
  BIT(int s) {
    size = 1;
    while (size < s)
      size *= 2;
    bit.assign(size, 0);
  }

  // 0-indexed
  void update(int id, T add) {
    id += 1;
    while (k <= size) {
      bit[k - 1] += add;
      k += k & -k;
    }
  }

  // [0,a]-sum
  T query(int a) {
    T s = 0;
    a++;
    while (a > 0) {
      s += bit[a - 1];  // def func
      a -= a & -a;
    }
    return s;
  }

  int size;
  vector<T> bit;
};
