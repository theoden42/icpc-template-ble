/**
 * Author: 0xarmin, theoden42
 * Date: 2024-12-31
 * License: CC0
 * Source: trust me bro
 * Description: Use this for simplicity in place of modular arithematic
 * c$. Status: Stress-tested
 */

ll madd(ll a, ll b) { return (a + b) % mod; }
ll msub(ll a, ll b) { return (((a - b) % mod) + mod) % mod; }
ll mmul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
ll mpow(ll base, ll exp) {
  ll res = 1;
  while (exp) {
    if (exp % 2 == 1) {
      res = (res * base) % mod;
    }
    exp >>= 1;
    base = (base * base) % mod;
  }
  return res;
}
ll minv(ll base) { return mpow(base, mod - 2); }
ll mdiv(ll a, ll b) { return mmul(a, minv(b)); }