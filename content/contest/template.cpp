#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using ordset =
    tree<T, null_type, less<T>, rb_tree_tag,
         tree_order_statistics_node_update>; // order_of_key, find_by_order
// GNU hash table
gp_hash_table<int, int> table;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// hash for pairs
struct chash {
  int operator()(pii x) const { return x.first * 31 + x.second; }
};
gp_hash_table<pii, int, chash> table;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
}
