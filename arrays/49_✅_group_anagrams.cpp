/*
Sorting 
Time complexity : O(m . nlogn)
Space complexity : O(m . n)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            res[sortedS].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};

/*
Hashmap
Time complexity : O(m. n) m - number of strings, n - length of longest string
Space complexity : O(m . n) for storing all strings and their groups 
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;

        for(string s : strs){
            vector<int> count(26, 0);
            for(char c : s){
                count[c - 'a'] += 1;
            }
            string sCount = "";
            for(int number : count){
                // add comma to avoid collisions
                sCount += to_string(number) + ",";
            }
            map[sCount].push_back(s);
        }

        for(auto itr = map.begin(); itr != map.end(); itr++){
            res.push_back(itr->second);
        }

        return res;    
    }
};
