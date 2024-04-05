#include<climits>
#include<vector>
using namespace std;
typedef long long ll;

//start: set goal :set
static ll nextSubSet(ll prev, ll set) {
  return (prev - 1) & set;
}

// start:00...011...1 goal : over 1<<n
static ll nextSizeKInN(ll prev, ll k, ll n) {
  ll x = prev & (-prev);
  ll y = prev + x;
  return ((prev & ~y) / x >> 1) | y;
}


