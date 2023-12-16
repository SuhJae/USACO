#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<unsigned long long> cows;
    unsigned long long cowCount;
    cin >> cowCount;

    cows.resize(cowCount);
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i];
    }

    stable_sort(cows.begin(), cows.end());

    unsigned long long maxTuition;
    unsigned long long maxTotalTuition = 0;

    for (int i = 0; i < cows.size() - 1; i++) {
        if ((i == 0) || (cows[i - 1] != cows[i])) {
            unsigned long long payingCowCount = cows.size() - i;
            unsigned long long localTuition = cows[i];
            unsigned long long localTotalTuition = payingCowCount * localTuition;

            if (localTotalTuition > maxTotalTuition) {
                maxTuition = localTuition;
                maxTotalTuition = localTotalTuition;
            }
        }
    }

    cout << maxTotalTuition << " " << maxTuition << endl;
    return 0;
}
