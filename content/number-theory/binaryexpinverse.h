/**
 * Author: Noam527
 * Date: 2019-04-24
 * License: CC0
 * Source: folklore
 * Description:
 * Status: tested
 */
#pragma once

const ll mod = 1000000007; // faster if const

ll binpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b = b >> 1;
  }
  return (ans % mod);
}

ll modinverse(ll a, ll b) { return binpow(a, b - 2) % mod; }
