#include <iostream>
#include <vector>
#include <string>

#define INF 2000000000

using namespace std;

int main() {
    int cowCount;
    cin >> cowCount;

    string cowLayout;
    cin >> cowLayout;

    bool edge = false;
    int chunkLen = 0;

    vector<int> chunkArray;

    for (int i = 0; i < cowCount; i++) {
        if (cowLayout[i] == '0') {
            if (chunkLen > 0) {
                if (edge) {
                    chunkArray.push_back(chunkLen * -1);
                } else {
                    chunkArray.push_back(chunkLen);
                }
            }
            chunkLen = 0;
            edge = false;
        } else {
            chunkLen++;
            if (i == 0) {
                edge = true;
            } else if (i == (cowCount - 1)) {
                chunkArray.push_back(chunkLen * -1);
            }
        }
    }

    int minchunk = INF;

    for (int chunkSize: chunkArray) {
        chunkSize = (chunkSize > 0) ? chunkSize : chunkSize * -2;

        if (chunkSize < minchunk) {
            minchunk = chunkSize;
        }
    }

    int maxDayPassed = (minchunk - 1) / 2;

    int maxSpread = 1 + maxDayPassed * 2;
    int cowSum = 0;

    for (int chunk: chunkArray) {
        chunk = abs(chunk);
        cowSum += chunk / maxSpread;
        if (chunk % maxSpread != 0) {
            cowSum++;
        }
    }

    cout << cowSum;
    return 0;
}
