#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


unsigned int countCows(vector<unsigned int> sortedCows, unsigned int value) {
    auto low = lower_bound(sortedCows.begin(), sortedCows.end(), value);
    auto upper = upper_bound(sortedCows.begin(), sortedCows.end(), value);
    unsigned int count = upper - low;

    return count;
}


int main() {
    vector<unsigned int> cows;
    unsigned int cowCount;
    cin >> cowCount;

    cows.resize(cowCount);
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i];
    }

    stable_sort(cows.begin(), cows.end());

    vector<unsigned int> willingTuition;
    vector<unsigned int> payingCows;

    for (unsigned int i = 0; i < cowCount;) {
        willingTuition.push_back(cows[i]);
        unsigned int paying = countCows(cows, cows[i]);
        payingCows.push_back(paying);

        i += paying;
    }

    unsigned int maxTuition;
    unsigned long long maxTotalTuition{0};

    unsigned int localPayingCount{0};

    for (unsigned int i = payingCows.size() - 1; i > 0; i--) {
        localPayingCount += payingCows[i];

        unsigned long long localTotalTuition = (unsigned long long) localPayingCount * willingTuition[i];

        if (localTotalTuition >= maxTotalTuition) {
            maxTotalTuition = localTotalTuition;
            maxTuition = willingTuition[i];
        }
    }

    cout << maxTotalTuition << " " << maxTuition << endl;

    return 0;
}
