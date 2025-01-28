class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>s;
        for(int x: candyType) s.insert(x);
        return min(s.size(),(candyType.size()/2));
    }
};
