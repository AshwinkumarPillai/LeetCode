// Using set as window.
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k <= 0) return false;
        set<long>s;
        int n = nums.size();
        s.insert((long)nums[0]);
        for(int i=1;i<n;i++){
            long val = nums[i];
            long minval = val - t;
            long maxval = val + t;
            auto it = s.upper_bound(minval - 1);
            if(it != s.end() && *it <= maxval) return true;    
            s.insert(val);
            if(s.size() > k) s.erase(nums[i-k]);
        }
        return false;
    }
};

// Using bucket
class Solution {
public:
    long getBucketId(long x,long w){
        return x<0 ? (x+1)/w-1 : x/w;
    }
  
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k <= 0) return false;
        map<long,long>m;
        long w = long(t) +1;
        for(int i=0;i<nums.size();i++){
            long val = nums[i];
            long id = getBucketId(val,w);
            if(m.find(id) != m.end()) return true;
            if(m.find(id-1) != m.end() && abs(val - m[id-1]) < w) return true;
            if(m.find(id+1) != m.end() && abs(val - m[id+1]) < w) return true;
            m[id] = val;
            if(i>=k) m.erase(getBucketId(nums[i-k],w));
        }
        return false;
    }
};

