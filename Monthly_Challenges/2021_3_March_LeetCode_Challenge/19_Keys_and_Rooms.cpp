// Using Stack
class Solution {
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        visited[0] = true;
        stack<int>s;
        s.push(0);
        while(!s.empty()){
            int i = s.top();s.pop();
            for(int x: rooms[i]) {
                if(!visited[x]){
                    s.push(x);
                    visited[x] = true;
                }
                
            }
        }
        for(int x: visited) if(!x) return x;
        return true;
    }
};

// Using Recursion
class Solution {
public:
    
    void travelRooms(vector<vector<int>>& rooms, vector<bool>& visited, int i){
        if(visited[i]) return;
        visited[i] = true;
        for(int x: rooms[i]){
            travelRooms(rooms, visited, x);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        travelRooms(rooms,visited,0);
        for(int x: visited) if(!x) return x;
        return true;
    }
};
