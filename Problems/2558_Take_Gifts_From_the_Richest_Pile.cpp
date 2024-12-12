class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> heap;
        long long ans = 0;
        for (int gift : gifts)
        {
            heap.push(gift);
            ans += gift;
        }

        while (k-- != 0)
        {
            int maxGift = heap.top();
            heap.pop();
            ans -= maxGift;
            int remaining = floor(sqrt(maxGift));
            heap.push(remaining);
            ans += remaining;
        }

        return ans;
    }
};