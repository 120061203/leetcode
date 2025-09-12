#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 你的程式碼寫在這裡
        //generate unordered map to store data
        unordered_map<string, vector<string>> mp;
        //travasal input each words
        for (int i =0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            //sort words and cout freqs
             //insert into unordered map
            mp[key].push_back(strs[i]);
        }
        //find same words as same group
        //return each group
        vector<vector<string>> res;
        for(auto& pair:mp){
            res.push_back(pair.second);
        }
        return res;
        
    }
};
