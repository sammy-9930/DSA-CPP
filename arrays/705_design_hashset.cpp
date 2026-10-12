/*
Brute force solution
time complexity: O(n) for each function call
space complexity: O(n)
*/

class MyHashSet {
public:
    vector<int> data;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(data.begin(), data.end(), key) == data.end())
            data.push_back(key);
    }
    
    void remove(int key) {
        auto itr = find(data.begin(), data.end(), key);
        if(itr != data.end()){
            data.erase(itr);
        }
    }
    
    bool contains(int key) {
        if(find(data.begin(), data.end(), key) != data.end())
            return true;
        return false;
    }
};

/*
Boolean array
time complexity : O(1)
space complexity : O(1000000) since the key is in the range [0, 1000000]
*/
class MyHashSet {
public:
    vector<bool> data;
    MyHashSet() : data(1000001, false){
        
    }
    
    void add(int key) {
        data[key] = true;
    }
    
    void remove(int key) {
        data[key] = false;
    }
    
    bool contains(int key) {
        if(data[key])
            return true;
        return false;
    }
};
