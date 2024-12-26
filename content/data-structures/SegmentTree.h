/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description:
 * O(\log N) Status: stress-tested
 */
#pragma once
struct segtree {
  int len, maxxn = 1e18;
  vector<int> minn;
  void init(int n) {
    len = 1;
    while (n > len)
      len *= 2;
    minn.assign(2 * len, maxxn);
  }
  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1)
      minn[x] = v;
    else {
      int m = (lx + rx) / 2;
      if (i < m)
        set(i, v, 2 * x + 1, lx, m);
      else
        set(i, v, 2 * x + 2, m, rx);
      minn[x] = min(minn[2 * x + 1], minn[2 * x + 2]);
    }
  }
  void set(int i, int v) { set(i, v, 0, 0, len); }
  int range(int l, int r, int x, int lx, int rx) {
    if (l >= rx or r <= lx)
      return maxxn;
    if (l <= lx and rx <= r)
      return minn[x];
    int m = (lx + rx) / 2;
    auto a = range(l, r, 2 * x + 1, lx, m);
    auto b = range(l, r, 2 * x + 2, m, rx);
    return min(a, b);
  }
  int range(int l, int r) { return range(l, r + 1, 0, 0, len); }
};