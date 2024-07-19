https://leetcode.com/problems/design-phone-directory/?envType=company&envId=google&favoriteSlug=google-thirty-days&status=TO_DO&difficulty=MEDIUM%2CEASY

class PhoneDirectory {
public:
    vector<bool>isSlotAvailable;
    queue<int>availableSlotsQueue;
    PhoneDirectory(int maxNumbers) {
        isSlotAvailable.resize(maxNumbers, true);
        for(int i=0;i < maxNumbers;i++){
            availableSlotsQueue.push(i);
        }
    }
    
    int get() {
        if(availableSlotsQueue.empty()) return -1;

        int slot = availableSlotsQueue.front();
        availableSlotsQueue.pop();

        isSlotAvailable[slot] = false;

        return slot;
    }
    
    bool check(int number) {
        return isSlotAvailable[number];
    }
    
    void release(int number) {
        if(!isSlotAvailable[number]){
            isSlotAvailable[number] = true;
            availableSlotsQueue.push(number);
        }
    }
};
