https://leetcode.com/problems/design-a-number-container-system/?envType=daily-question&envId=2025-02-08

class NumberContainers {
public:
    unordered_map<int,set<int>>numberToIndices;
    unordered_map<int,int>indexToNumber;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNumber.find(index) != indexToNumber.end()){
            numberToIndices[indexToNumber[index]].erase(index);
            if(numberToIndices[indexToNumber[index]].size() == 0) numberToIndices.erase(indexToNumber[index]);
        }

        numberToIndices[number].insert(index);
        indexToNumber[index] = number;
    }
    
    int find(int number) {
        if(numberToIndices.find(number) == numberToIndices.end()) return -1;
        return *numberToIndices[number].begin();
    }
};
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */