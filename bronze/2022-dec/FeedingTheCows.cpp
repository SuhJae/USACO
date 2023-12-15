#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool is_covering_right(string &cowLayout, char &cowType, int &curLocation, int &cowRange) {
    if (curLocation + cowRange >= cowLayout.size()) {
        return false;
    }
    return (curLocation + cowRange) == cowType;
}

int main() {
    int testCase;
    cin >> testCase;

    // each test case
    for (int c = 0; c < testCase; c++) {
        int stringLen, cowRadius;
        int grassPlacement = 0;
        string cowLayout;

        cin >> stringLen >> cowRadius;
        cin >> cowLayout;

        vector<char> grassLayout(stringLen, '.');
        vector<bool> gCoverage(stringLen);
        vector<bool> cCoverage(stringLen);

        for (int i = 0; i < stringLen; i++) {
            // when the cow without the coverage is found, first place the grass cowRadius right from i
            // on conflict, check if the right end of the grass is covering additional cow. If not, move one left
            // and place a new one.

            vector<bool> *coverageVector = (cowLayout[i] == 'G') ? &gCoverage : &cCoverage;
            char currentCow = cowLayout[i];


            // when coverage is not found
            if (!(*coverageVector)[i]) {
                // check i right
                int placementCur = i + cowRadius;

                // when range our of range
                if (placementCur >= stringLen) {
                    placementCur = stringLen - 1;
                }

                // loop for the possible placements
                vector<int> potentialPlacement;

                for (int j = placementCur; j >= i; j--) {
                    potentialPlacement.push_back(j);
                    if (is_covering_right(cowLayout, currentCow, j, cowRadius)) {
                        break;
                    }
                }

                // place the furthest one
                if (potentialPlacement.size() == 1) {
                    int location = potentialPlacement[0];

                    if (grassLayout[location] != '.' && islower(grassLayout[location])) {
                        // move movable left
                        grassLayout[location - 1] = grassLayout[location];
                    }
                    // capital to mark it is not movable
                    grassLayout[location] = currentCow;
                } else {
                    for (int location: potentialPlacement) {
                        if (grassLayout[location] == '.') {
                            // to lower to mark movable to left
                            grassLayout[location] = char(tolower(currentCow));
                            break;
                        }
                    }
                }

                // update the range
                int low = potentialPlacement[potentialPlacement.size() - 1] - cowRadius;
                int high = potentialPlacement[0] + cowRadius;

                if (low < 0) {
                    low = 0;
                }
                if (high >= stringLen) {
                    high = stringLen - 1;
                }

                for (int j = low; j <= high; j++) {
                    (*coverageVector)[j] = true;
                }
                grassPlacement++;
            }
        }

        cout << grassPlacement << endl;
        for (char placement: grassLayout) {
            cout << char(toupper(placement));
        }
        cout << endl;
    }

    return 0;
}
