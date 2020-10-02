// Discussion solution
class Solution {
public:
    map<int,vector<int>> mp;
    
    int total=0;
    Solution(vector<vector<int>>& rects) {
        for(int i=0;i<rects.size();i++){
            int x1=rects[i][0];
            int y1=rects[i][1];
            int x2=rects[i][2];
            int y2=rects[i][3];
            
            int sum = (x2 - x1 + 1)*(y2 - y1 + 1);
            vector<int> temp = {total,total + sum - 1,x1,y1,x2,y2};
            mp[i]=temp;
            total=total+sum;
        }
    }
    
    vector<int> pick() {
        int temp=rand()%total;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            int x=((*it).second)[0];
            int y=((*it).second)[1];
            int x1=((*it).second)[2];
            int y1=((*it).second)[3];
            int x2=((*it).second)[4];
            int y2=((*it).second)[5];
            
            if(temp>=x&&temp<=y){
                int curr=temp-x;
                
                int w=(x2-x1+1);
                int h=(y2-y1+1);
                
                int hy=y1+(curr)/w;
                int wx=x1+(curr)%w;
                
                vector<int> ans={wx,hy};
                return ans;
            }
        }
        vector<int> result={0,0};
        return result;
    }
};

// Official Solution
class Solution {
public:

    vector<vector<int>> r;
    vector<int> prefix;
    int total = 0;
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;

    Solution(vector<vector<int>> rects) {
        r = rects;
        for (auto& x : rects) {
            total += (x[2] - x[0] + 1) * (x[3] - x[1] + 1);
            prefix.push_back(total);
        }
        uni = uniform_int_distribution<int>{0, total - 1};
    }

    vector<int> pick() {
        int target = uni(rng);

        int low = 0;
        int high = r.size() - 1;
        while (low != high) {
            int mid = (low + high) / 2;
            if (target >= prefix[mid]) low = mid + 1;
            else high = mid;
        }

        auto& x = r[low];
        int width = x[2] - x[0] + 1;
        int height = x[3] - x[1] + 1;
        int base = prefix[low] - width * height;
        return {x[0] + (target - base) % width, x[1] + (target - base) / width};
    }
};
