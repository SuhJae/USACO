#include <iostream>
#include <vector>

using namespace std;


int main() {
    int testCase;
    cin >> testCase;

    vector<bool> validResult;

    for (int t = 0; t < testCase; t++) {
        int testDataLength, testDataCount;
        cin >> testDataLength >> testDataCount;

        vector<string> testData(testDataCount);
        vector<char> testResult(testDataCount);

        for (int i = 0; i < testDataCount; i++) {
            string singleTestIn;
            int singleTestOut;
            cin >> singleTestIn >> singleTestOut;

            testData[i] = singleTestIn;
            testResult[i] = singleTestOut;
        }

        bool isValid = false;

        // loop all the chars
        for (int i = 0; i < testDataLength; i++) {
            char oneValue = '.';
            char zeroValue = '.';
            bool oneUnified = false;
            bool zeroUnified = false;

            //2 4
            //00 testData[0][0]
            //01 testData[1][0]
            //10 testData[2]
            //11 testData[3]

            // 0101
            // 1010
            // 1001

            //1 1   index=0
            //1 1   index=1

            // loop all the tests
            for (int j = 0; j < testDataCount; j++) {
                char current = testData[j][i];
                char result = testResult[j];
                char *valuePtr = (current == '1') ? &oneValue : &zeroValue;
                bool *unifiedPtr = (current == '1') ? &oneUnified : &zeroUnified;

                if (*valuePtr == '.') {
                    *valuePtr = result;
                    *unifiedPtr = true;
                } else if ((*unifiedPtr) && (*valuePtr != result)) {
                    *unifiedPtr = false;
                }
            }

            if (oneUnified || zeroUnified) {
                isValid = true;
                break;
            }
        }
        validResult.push_back(isValid);
    }

    for (bool result: validResult) {
        cout << (result ? "OK" : "LIE") << endl;
    }

    return 0;
}
