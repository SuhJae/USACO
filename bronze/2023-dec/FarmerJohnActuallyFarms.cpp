#include <limits>
#include <iostream>
#include <vector>
#include <algorithm>

#define LL_INF std::numeric_limits<long long>::max()

typedef long long ll;
using namespace std;

int main() {
    int testCase;
    cin >> testCase;

    vector<ll> results;
    results.resize(testCase);

    for (int test = 0; test < testCase; test++) {
        int plantCount;
        cin >> plantCount;

        //     FJ index    height  growth
        vector<pair<int, pair<ll, ll>>> plants;
        plants.resize(plantCount);

        // initial height
        for (int i = 0; i < plantCount; i++) {
            cin >> plants[i].second.first;
        }

        // growth rate
        for (int i = 0; i < plantCount; i++) {
            cin >> plants[i].second.second;
        }

        // FJ index (how many shorter plants to this
        for (int i = 0; i < plantCount; i++) {
            cin >> plants[i].first;
        }

        sort(plants.begin(), plants.end());
        ll minRange = 0;
        ll maxRange = LL_INF;
        bool isInvalid = false;

        // iterates from the plant that needs to be largest to smallest in the end
        for (int i = 0; i < plantCount - 1; i++) {
            ll heightShort = plants[i + 1].second.first;
            ll growthShort = plants[i + 1].second.second;
            ll heightLong = plants[i].second.first;
            ll growthLong = plants[i].second.second;

            if (heightShort < heightLong) {
                // when initial height is in the right oder
                if (growthShort > growthLong) {
                    // find the max
                    ll heightDiff = heightLong - heightShort;
                    ll growthDiff = growthShort - growthLong;

                    ll localMax = (heightDiff / growthDiff);

                    if (heightDiff % growthDiff != 0) {
                        localMax++;
                    }

                    if (localMax < maxRange) {
                        maxRange = localMax;
                    }
                }
                // when initial height is in the ! correct order (including same)
            } else {
                if (growthShort >= growthLong) {
                    isInvalid = true;
                    break;
                } else {
                    // find the min
                    ll heightDiff = heightShort - heightLong;
                    ll growthDiff = growthLong - growthShort;

                    ll localMin = (heightDiff / growthDiff) + 1;

                    if (localMin > minRange) {
                        minRange = localMin;
                    }
                }
            }
        }
        results[test] = (isInvalid || minRange > maxRange) ? -1 : minRange;
    }

    for (ll result: results) {
        cout << result << endl;
    }

    return 0;
}
