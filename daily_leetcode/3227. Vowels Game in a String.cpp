#include <string>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        // 母音定義
        int vowel_cnt = 0;
        for (auto ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowel_cnt++;
            }
        }
        return vowel_cnt > 0;
    }
};
