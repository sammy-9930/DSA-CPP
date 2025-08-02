// Brute force 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto number: nums)
            freq[number] += 1;
        for (auto i = freq.begin(); i != freq.end(); i++){
            if (i->second == 1)
                return i->first;
        }
        return 0;
    }
};

// hashset
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> freq;
        for (int number: nums){
            if (freq.count(number))
            {
                freq.erase(number);
            }
            else{
                freq.insert(number);
            }
        }
        return *freq.begin();
    }
};

// Bit manipulation 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int number: nums)
            res = res ^ number;
        return res;
    }
};