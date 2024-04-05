#define ATCODER
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <climits>
#include <set>
#include <map>
#include <list>
#include <random>
#include <iterator>
#include <bitset>
#include <chrono>
#include <type_traits>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;


#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define ROF(i, a, b) for (ll i = (b - 1); i >= (a); i--)
#define PER(i, n) for (ll i = n - 1; i >= 0; i--)
#define VL vector<ll>
#define VVL vector<vector<ll>>
#define VP vector<pair<ll, ll>>
#define LPQ(T) priority_queue<T, vector<T>, greater<T>>
#define all(i) begin(i), end(i)
#define SORT(i) sort(all(i))
#define BITI(i) (1 << i)
#define BITSET(x, i) x | (ll(1) << i)
#define BITCUT(x, i) x & ~(ll(1) << i)
#define EXISTBIT(x, i) (((x >> i) & 1) != 0)
#define ALLBIT(n) (ll(1) << n - 1)
#define CHMAX(n, v) n = n < v ? v : n
#define CHMIN(n, v) n = n > v ? v : n
#define MP(a, b) make_pair(a, b)
#define DET2(x1, y1, x2, y2) x1 *y2 - x2 *y1
#define DET3(x1, y1, z1, x2, y2, z2, x3, y3, z3) x1 *y2 *z3 + x2 *y3 *z1 + x3 *y1 *z2 - z1 *y2 *x3 - z2 *y3 *x1 - z3 *y1 *x2
#define INC(a)      \
  for (auto &v : a) \
    v++;
#define DEC(a)      \
  for (auto &v : a) \
    v--;
#define SQU(x) (x) * (x)

#ifdef ATCODER
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using mint2 = modint998244353;
#endif
template <typename T = ll>
vector<T> read(size_t n)
{
  vector<T> ts(n);
  for (size_t i = 0; i < n; i++)
    cin >> ts[i];
  return ts;
}

template <typename TV, const ll N>
void read_tuple_impl(TV &) {}
template <typename TV, const ll N, typename Head, typename... Tail>
void read_tuple_impl(TV &ts)
{
  get<N>(ts).emplace_back(*(istream_iterator<Head>(cin)));
  read_tuple_impl<TV, N + 1, Tail...>(ts);
}
template <typename... Ts>
decltype(auto) read_tuple(size_t n)
{
  tuple<vector<Ts>...> ts;
  for (size_t i = 0; i < n; i++)
    read_tuple_impl<decltype(ts), 0, Ts...>(ts);
  return ts;
}

using val = ll;
using func = ll;

val op(val a, val b)
{
  return max(a, b);
}
val e() { return -1e18; }

val mp(func f, val a)
{
  return a + f;
}
func comp(func f, func g)
{
  return f + g;
}
func id() { return 0; }

ll di[4] = {1, 0, -1, 0};
ll dj[4] = {0, 1, 0, -1};
ll si[4] = {0, 3, 3, 0};
ll sj[4] = {0, 0, 3, 3};
// ll di[4] = { -1,-1,1,1 };
// ll dj[4] = { -1,1,-1,1 };
ll di8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
ll dj8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void solve()
{
  return;
}

int main()
{
  ll t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
