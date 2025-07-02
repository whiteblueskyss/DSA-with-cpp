#include <bits/stdc++.h>
using namespace std;
#define ll long long int


ll calc(ll n, ll a, ll b, ll c) {
  return a * n + b * n * log2(n) + c * n * n * n;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll a, b, c, k;
        cin >> a >> b >> c >> k;

        ll low = 1, high = 1e6;
        ll ans = 0;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll value = calc(mid, a, b, c);

            if (value == k) {
                ans = mid;
                break;
            }
            else if (value < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // After binary search, check exact match
        if (calc(ans, a, b, c) == k) {
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
