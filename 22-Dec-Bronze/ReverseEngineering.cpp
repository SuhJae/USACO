#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool checkSet(const vector<bitset<101>>& testData, bool firstVal, bool secondVal, bool elseVal,
              bool invertFirstCondition, bool invertSecondCondition,
              int ifOneCursor, int ifTwoCursor) {

    for (const bitset<101> &test: testData) {
        bool firstCondition = test[ifOneCursor] != invertFirstCondition;
        bool secondCondition = test[ifTwoCursor] != invertSecondCondition;
        bool expected = test[100];

        if (firstCondition) {
            if (expected != firstVal) return false;
        }
        else if (secondCondition) {
            if (expected != secondVal) return false;
        }
        else {
            if (expected != elseVal) return false;
        }
    }
    return true;
}


int main() {
    int testCase;
    cin >> testCase;

    vector<bool> validResult;

    for (int t = 0; t < testCase; t++) {
        int testDataInLength, testDataCount;
        cin >> testDataInLength >> testDataCount;

        // 0-100 will be char, 101 as result
        vector<bitset<101>> testData;

        for (int l = 0; l < testDataCount; l++) {
            bitset<101> singleTest;
            string singleTestIn;
            int singleTestOut;

            cin >> singleTestIn >> singleTestOut;

            for (int i = 0; i < testDataInLength; i++) {
                if (singleTestIn[i] == '1') {
                    singleTest.set(i);
                }
            }

            if (singleTestOut == 1) {
                singleTest.set(100);
            }
            testData.push_back(singleTest);
        }


        bool overallValid = false;

        for (int ifOneCursor = 0; ifOneCursor < testDataInLength; ifOneCursor++) {
            for (int ifTwoCursor = 0; ifTwoCursor < testDataInLength; ifTwoCursor++) {
                for (int mask = 0; mask < (1 << 5); ++mask) {
                    bool param1 = (mask & (1 << 0)) != 0;
                    bool param2 = (mask & (1 << 1)) != 0;
                    bool param3 = (mask & (1 << 2)) != 0;
                    bool param4 = (mask & (1 << 3)) != 0;
                    bool param5 = (mask & (1 << 4)) != 0;

                    bool localValid = checkSet(testData, param1, param2, param3, param4, param5, ifOneCursor,
                                               ifTwoCursor);
                    if (localValid) {
                        overallValid = true;
                        break;
                    }
                }
            }
        }

        validResult.push_back(overallValid);
    }

    for (bool result: validResult) {
        cout << (result ? "OK" : "LIE") << endl;
    }

    return 0;
}

//1
//
//100 1
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111 0
