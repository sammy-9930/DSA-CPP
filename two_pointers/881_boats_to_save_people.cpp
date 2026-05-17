class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int boats = 0;
        while (i <= j){
            if (people[i] + people[j] <= limit){
                i++;
            }
            j--;
            boats += 1;
        }
        return boats;
    }
};

/*
alternate more intuitive solution 
time complexity: o(n) n - number of people 
space complexity: o(1)
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size()-1;
        int boat_count = 0;
        while (l <= r){
            int cur_wt = people[l] + people[r];
            if (cur_wt <= limit){
                boat_count += 1;
                l += 1;
                r -= 1;
            }
            else{
                boat_count += 1;
                r -= 1;
            }
        }
        return boat_count; 
    }
};


