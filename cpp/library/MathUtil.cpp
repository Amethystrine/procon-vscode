#ifdef false

#include <vector>
#include <algorithm>
#include <numeric>
typedef long long ll;
using namespace std;

ll prime[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,167,181,191,193,197,199 };

template<typename T>
void Factorical(ll siz, vector<T>& out) {
  out.resize(siz + 1);
  out[0] = T(1);
  for (ll i = 0; i < siz; i++) {
    out[i + 1] = out[i] * (i + 1);
  }
}

template<typename T>
T Combi(ll a, ll b, vector<T>& fact) {
  return fact[a] / (fact[b] * fact[a - b]);
}

template<typename T>
T Power(T var, ll p) {
  if (p == 1)
    return var;
  T ans = Power(var * var, p >> 1);
  if (p & 1)
    ans = ans * var;;
  return ans;
}

void Factorize(ll val, vector<ll>& out) {
  if (val <= 1) return;
  for (ll i = 2; i * i <= val; i++) {
    if (val % i == 0) {
      out.push_back(i);
      Factorize(val / i, out);
      return;
    }
  }
  out.push_back(val);
}

void ExtGcd(ll aIn, ll& xOut, ll bIn, ll& yOut) {
  ll g = gcd(aIn, bIn);
  ll a = aIn / g;
  ll b = bIn / g;
  xOut = 1;
  yOut = 0;
  if (a < b) {
    swap(a, b);
    swap(xOut, yOut);
  }
  while (b > 0) {
    ll t = a / b;
    xOut -= t * yOut;
    a -= t * b;
    swap(a, b);
    swap(xOut, yOut);
  }
  yOut = (g - aIn * xOut) / bIn;
}

template<typename T>
vector<T> convolution(vector<T>& a, vector<T>& b) {
  vector<T> ans(a.size() + b.size() - 1);
  REP(i, a.size()) {
    REP(j, b.size()) {
      ans[i + j] += a[i] * b[j];
    }
  }
  return ans;
}

vector<vector<ll>> GetStaring1(ll n, ll k) {
  vector ans(n + 1, vector<ll>(k + 1));
  ans[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      ans[i + 1][j + 1] = i * ans[i][j + 1] + ans[i][j];
    }
  }
  return ans;
}

vector<vector<ll>> GetStaring2(ll n, ll k) {
  vector ans(n + 1, vector<ll>(k + 1));
  ans[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      ans[i + 1][j + 1] = (j + 1) * ans[i][j + 1] + ans[i][j];
    }
  }
  return ans;
}

template<typename T>
T GetBell(ll n, ll k) {
  vector<T> revFact(k + 1);
  revFact[0] = 1;
  for (ll i = 0; i < k; i++) {
    revFact[i + 1] = revFact[i] / (i + 1);
  }
  vector<T> alterRevFactSum(k + 1);
  alterRevFactSum[0] = revFact[0];
  for (ll i = 0; i < k; i++) {
    alterRevFactSum[i + 1] = i % 2 ? alterRevFactSum[i] + revFact[i + 1] : alterRevFactSum[i] - revFact[i + 1];
  }

  T ans = 0;
  for (ll i = 0; i <= k; i++) {
    ans += Power(i, n) * revFact[i] * alterRevFactSum[k - i];
  }
  return ans;
}


template<typename T>
class FactoricalLagrangeInterpolation {
public:
  FactoricalLagrangeInterpolation(ll d = 0) {
    ys.resize(d + 1);
  }

  T DoLagrange(ll n) {
    int siz = ys.size();

    T tN = n;

    T factN = 1;            // nからn-dまでの組合せ積(0がある場合、それを除いたもの)
    vector<T> factD(siz);   // dまでの階乗メモ

    for (int i = 0; i < siz; i++) {
      if (tN - i == 0) {
        return ys[i];     // 巡回がsizより小さい場合、これは使えない
      }
      factD[i] = i ? factD[i - 1] * i : 1;
      factN *= tN - i;
    }

    T ans = 0;
    for (ll i = 0; i < siz; i++) {
      T plus = ys[i] * factN / ((tN - i) * factD[i] * factD[siz - i - 1]);
      plus *= (siz + i) % 2 ? 1 : -1;
      ans += plus;
    }
    return ans;
  }

  vector<T> ys;
};

class Rational {
public:
  Rational(ll nn = 0, ll dd = 1) {
    n = nn; d = dd; Reduction();
  }
  Rational operator+() const { return *this; }
  Rational operator-() const { return *this * -1; }

  Rational& operator=(ll nn) { n = nn; d = 1; return *this; }
  Rational& operator = (const Rational& r) { n = r.n; d = r.d; return *this; }
  Rational& operator += (const Rational& r) { n = n * r.d + r.n * d; d *= r.d; Reduction(); return *this; }
  Rational& operator -= (const Rational& r) { n = n * r.d - r.n * d; d *= r.d; Reduction(); return *this; }
  Rational& operator *= (const Rational& r) { n *= r.n; d *= r.d; Reduction();  return *this; }
  Rational& operator /= (const Rational& r) { n *= r.d; d *= r.n; Reduction();  return *this; }

  bool operator ==(const Rational& r) { return n * r.d == r.n * d; }
  bool operator !=(const Rational& r) { return !(*this == r); }
  bool operator <(const Rational& r) {
    if (d == 0 && r.d == 0) return n < 0 && 0 < r.n;
    if (r.d == 0) return r.n > 0;
    if (d == 0) return n < 0;
    return n * r.d < r.n* d;
  }
  bool operator >(const Rational& r) {
    if (d == 0 && r.d == 0) return r.n < 0 && 0 < n;
    if (r.d == 0) return r.n < 0;
    if (d == 0) return n > 0;
    return n * r.d < r.n* d;
  }

  bool operator <=(const Rational& r) { return !(*this > r); }
  bool operator >=(const Rational& r) { return !(*this < r); }

  void Reduction() {
    ll g = gcd(n, d);
    if (g == 0)return;
    if (d < 0)g *= -1;
    n /= g; d /= g;
  }
  // d is not negative
  ll n, d;
};

static Rational operator + (const Rational& l, const Rational& r) { return Rational(l) += r; }
static Rational operator - (const Rational& l, const Rational& r) { return Rational(l) -= r; }
static Rational operator * (const Rational& l, const Rational& r) { return Rational(l) *= r; }
static Rational operator / (const Rational& l, const Rational& r) { return Rational(l) /= r; }
static bool operator < (const Rational& l, const Rational& r) { return Rational(l) < r; }
static bool operator > (const Rational& l, const Rational& r) { return Rational(l) > r; }
static bool operator <= (const Rational& l, const Rational& r) { return Rational(l) <= r; }
static bool operator >= (const Rational& l, const Rational& r) { return Rational(l) >= r; }

int main() {
  auto s1 = GetStaring1(5, 5);
  auto s2 = GetStaring2(5, 5);
  auto b = GetBell<mint>(5, 5);

  return 0;
}

#endif TEST