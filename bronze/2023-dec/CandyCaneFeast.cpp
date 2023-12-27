#include <vector>
#include <iostream>

typedef unsigned long long ull;
using namespace std;


int main() {
    vector<ull> cowHeights;
    vector<ull> candyHeights;
    ull cowCount;
    ull candyCount;

    cin >> cowCount >> candyCount;

    cowHeights.resize(cowCount);
    candyHeights.resize(candyCount);

    for (ull i = 0; i < cowCount; i++) {
        cin >> cowHeights[i];
    }
    for (ull i = 0; i < candyCount; i++) {
        cin >> candyHeights[i];
    }

    for (ull i = 0; i < candyCount; i++) {
        ull lowest = 1;
        ull top = candyHeights[i];

        for (ull j = 0; j < cowCount; j++) {
            ull cowHeight = cowHeights[j];
            ull eatenUnit;
            if (cowHeight >= lowest) {
                if (cowHeight > top) {
                    eatenUnit = top;
                } else {
                    eatenUnit = cowHeight;
                }
                eatenUnit = eatenUnit - lowest + 1;
                lowest += eatenUnit;
                cowHeights[j] = cowHeight + eatenUnit;
                if (lowest > top) {
                    break;
                }
            }
        }
    }

    for (ull i = 0; i < cowCount; i++) {
        cout << cowHeights[i] << endl;
    }

    return 0;
}
