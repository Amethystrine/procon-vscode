// todo : factorize
// todo : 

#ifdef false

////////// Mod
#include <iostream>
typedef long long ll; 
using namespace std;

const ll MOD = 1e9 + 7;
const int MaxIntPower = 30;
class Mod {
public:
  ll var;
  Mod(ll v = 0) { var = v % MOD; }
  void operator = (ll r) { var = r % MOD; }
  void operator = (Mod r) { var = r.var; }
  Mod operator + (Mod r) { return (var + r.var) % MOD; }
  Mod operator - (Mod r) { return (var - r.var + MOD) % MOD; }
  Mod operator * (Mod r) { return (var * r.var) % MOD; }
  Mod operator / (Mod r) { return (var * r.Reverse().var) % MOD; }

  void operator += (Mod r) { var = (var + r.var) % MOD; }
  void operator -= (Mod r) { var = (var - r.var + MOD) % MOD; }
  void operator *= (Mod r) { var = (var * r.var) % MOD; }
  void operator /= (Mod r) { var = (var + r.Reverse().var) % MOD; }

  bool operator ==(const Mod& r) { return var == r.var; }
  bool operator <(const Mod& r) { return var < r.var; }
  bool operator !=(const Mod& r) { return var != r.var; }

  Mod Power(int p) {
    if (var == 0 || var == 1) return var;
    while (p < 0) p += MOD - 1;
    p = p % (MOD - 1);
    Mod ans = 1;    
    Mod tmpVar = var;
    while (bit >= 1) {
      if (p & 1)
        ans *= tmpVar;
      tmpVar *= tmpVar;
      p >>= 1;
    }
    return ans;
  }

  Mod Reverse() {
    ll a = var;
    ll b = MOD;
    ll u = 1;
    ll v = 0;
    while (b > 0) {
      ll t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }

    Mod val;
    val.var = (u + MOD) % MOD;
    return val;
  }
};

istream& operator >>(istream& is, Mod& x) {
  ll t;
  is >> t;
  x = t;
  return (is);
}
ostream& operator <<(ostream& os, const Mod& x) {
  return os << x.var;
}

#endif