// Floyd's cycle detection or Tortoise-Hare method
class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += ((n % 10) * (n % 10));
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);
        } while (slow != fast);
        return slow == 1;
    }
};

// Use Set to track generated numbers
class Solution
{
public:
    int createSum(int n)
    {
        int sum = 0;
        while (n)
        {
            int r = n % 10;
            n /= 10;
            sum += (r * r);
        }
        return sum;
    }

    bool isHappy(int n)
    {
        unordered_set<int> visited;
        while (1)
        {
            n = createSum(n);
            if (visited.count(n) == 1)
            {
                return false;
            }
            visited.insert(n);
            if (n == 1)
                return true;
        }
    }
};