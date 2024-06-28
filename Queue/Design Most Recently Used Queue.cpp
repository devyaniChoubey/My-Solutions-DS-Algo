https://leetcode.com/problems/design-most-recently-used-queue/

class MRUQueue {
public:
    vector<deque<int>>buckets;
    int sqrtN;
    MRUQueue(int n) {
        vector<int>nums(n);

        for(int i=0;i < n;i++) nums[i] = i+1;

        sqrtN = ceil(sqrt(n));

        for(int i=0;i < n;i+=sqrtN){
            deque<int>chunk;
            for(int j=i;j < min(i+sqrtN, n);j++){
                chunk.push_back(nums[j]);
            }
            buckets.push_back(chunk);
        }
    }
    
    int fetch(int k) {
        k--;
        int bucket_idx = k/sqrtN;
        int nums_idx = k%sqrtN;

        deque<int>bucket = buckets[bucket_idx];
        int target_num = bucket[nums_idx];

        deque<int>new_bucket;

        for(int i=0;i < bucket.size();i++){
            if(i != nums_idx) new_bucket.push_back(bucket[i]);
        }

        buckets[bucket_idx] = new_bucket;

        buckets.back().push_back(target_num);

        for(int i=bucket_idx;i < buckets.size()-1;i++){
            deque<int>&left_bucket = buckets[i];
            deque<int>&right_bucket = buckets[i+1];

            left_bucket.push_back(right_bucket.front());
            right_bucket.pop_front();
        }

        return target_num;
    }
};
