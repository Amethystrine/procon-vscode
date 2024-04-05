#include<vector>
#include<climits>
using namespace std;
typedef long long ll;

template<typename T = ll>
class Matrix {
public:
  Matrix(ll l, ll c = 1) {
    low = l;
    column = c;
    var.resize(l);
    for (ll i = 0; i < l; i++) {
      var[i].assign(c, T(0));
    }
  }

  T& operator()(int i, int j = 0) {
    return var[i][j];
  }

  Matrix<T> operator+=(Matrix<T> m) {
    for (ll i = 0; i < low; i++) {
      for (ll j = 0; j < column; j++) {
        var[i][j] += m(i, j);
      }
    }
    return *this;
  }

  Matrix<T> operator -() {
    for (ll i = 0; i < low; i++) {
      for (ll j = 0; j < column; j++) {
        var[i][j] *= T(-1);
      }
    }
    return *this;
  }

  Matrix<T> operator-=(Matrix<T> m) {
    *this += -m;
    return *this;
  }

  Matrix<T> operator*=(T s) {
    for (ll i = 0; i < low; i++) {
      for (ll j = 0; j < column; j++) {
        var[i][j] *= s;
      }
    }
    return *this;
  }

  Matrix<T> operator/=(T s) {
    for (ll i = 0; i < low; i++) {
      for (ll j = 0; j < column; j++) {
        var[i][j] /= s;
      }
    }
    return *this;
  }


  Matrix<T> operator+(Matrix<T> m) {
    Matrix<T> ans = *this;
    return ans += m;
  }

  Matrix<T> operator-(Matrix<T> m) {
    Matrix<T> ans = *this;
    return ans -= m;
  }

  Matrix<T> operator*(T s) {
    Matrix<T> ans = *this;
    return ans *= s;
  }

  Matrix<T> operator/(T s) {
    Matrix<T> ans = *this;
    return ans /= s;
  }

  Matrix<T> operator*(Matrix<T> m) {
    Matrix<T> ans(low, m.column);
    for (ll i = 0; i < low; i++) {
      for (ll j = 0; j < m.column; j++) {
        for (ll k = 0; k < m.low; k++) {
          ans.var[i][j] ^= ((var[i][k]) & (m(k, j)));
        }
      }
    }
    return ans;
  }

  Matrix<T> Gaussian() {
    auto ans = *this;
    vector<ll> f(column, -1);
    for (ll j = 0; j < column; j++) {
      for (ll i = 0; i < low; i++) {
        if (ans.var[i][j] == 0) continue;
        if (f[j] == -1) {
          bool ok = true;
          for (ll k = 0; k < j; k++) {
            ok = ok && i != f[k];
          }
          if (ok) {
            f[j] = i;
            break;
          }
        }
      }
      if (f[j] == -1) {
        continue;
      }
      T rev = 1 / ans(f[j], j);
      for (ll i = 0; i < low; i++) {
        if (ans.var[i][j] == 0)continue;
        if (i == f[j])continue;
        T mul = ans.var[i][j] * rev;
        for (ll k = j; k < column; k++) {
          ans.var[i][k] -= ans.var[f[j]][k] * mul;
        }
      }
    }
    return ans;
  }

  T Determinant() {
    auto g = Gaussian();
    T ans = 1;
    for (ll i = 0; i < low; i++) {
      ans *= g(i, i);
    }
    return ans;
  }

  Matrix<T> SubMatrix(ll lowS, ll lowC, ll colS, ll colC) {
    Matrix<T> ans(lowC, colC);
    for (ll i = 0; i < lowC; i++) {
      for (ll j = 0; j < colC; j++) {
        ans(i, j) = var[lowS + i][colS + j];
      }
    }
    return ans;
  }

  Matrix<T> Inverse() {
    Matrix<T> ex(low, column * 2);
    for (ll i = 0; i < low; i++) {
      ex(i, column + i) = T(1);
      for (ll j = 0; j < column; j++) {
        ex(i, j) = var[i][j];
      }
    }
    auto g = ex.Gaussian();
    auto s = g.SubMatrix(0, low, column, column);
    for (ll i = 0; i < low; i++) {
      if (g.var[i][i] == 0) {
        return Matrix<T>(0, 0);
      }
      T inv = 1 / g.var[i][i];
      for (ll j = 0; j < column; j++) {
        s(i, j) *= inv;
      }
    }
    return s;
  }

  vector<vector<T>> var;
  ll low;
  ll column;
};

template<typename T>
static Matrix<T> operator*(const T& t, const Matrix<T>& m) {
  return m * t;
}
