class RandomizedSet {
    vector<int> v;     // this will store elements
    unordered_map<int, int> myMap;// for checking if it exists in set: it will store value->index
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(myMap.find(val) != myMap.end())  // this element is already present in set
            return false;
        v.push_back(val);                  // storing this element in array
        myMap[val] = v.size()-1;           // storing its index in map
        return true;
        
    }
    
    bool remove(int val) {
        if(myMap.find(val) == myMap.end())      // this elements doesn't exist in set
            return false;
        auto it = myMap.find(val);      // it->second is index of element to be removed
        v[it->second] = v.back();     // in array replacing current element with last element of array
        v.pop_back();                 // removing last element of array
        myMap[v[it->second]] = it->second; // updating index of element that was stored in place of removed one
        myMap.erase(val);
        return true;
        
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */