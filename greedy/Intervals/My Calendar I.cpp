https://leetcode.com/problems/my-calendar-i/description/


         it--        it
     ... |----| ... |----| ...
            |---------|
      start          end
if (--it)->second > start  or end > it->first, there is an overlap.


//binary seach

class MyCalendar {
public:
    set<pair<int,int>>bookings;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = bookings.lower_bound({start, end});

        if(it != bookings.end() && it->first < end) return false;
        if(it != bookings.begin() && (--it)->second > start) return false;

        bookings.insert({start, end});

        return true;

    }
};


//brute force

class MyCalendar {
public:
    vector<pair<int,int>>bookings;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:bookings){
            int s1 = it.first, e1 = it.second;
            if(e1 > start && end > s1) return false;
        }

        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */