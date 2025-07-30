// brute force 
class Solution {
public:
    int hammingWeight(int n) {
        int total_count = 0;
        vector<int> binary_rep;
        while (n > 0){
            int rem = n % 2;
            binary_rep.push_back(rem);
            n = n / 2;
        }
        for (int i = 0; i < binary_rep.size(); i++){
            if (binary_rep[i] == 1){
                total_count += 1; 
            }
        }
        return total_count; 
    }
};

// Bit mask (optimal)
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n > 0){
            n = n & (n-1);
            count ++;
        }
        return count;
    }
};
