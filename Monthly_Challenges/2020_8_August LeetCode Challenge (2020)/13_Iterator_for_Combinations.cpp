// Backtracking
class CombinationIterator {
public:
    vector<string>list;
    int index = 0;
    
    void backtrack(int j,string& curr,string& characters,int n,int k){
        if(curr.length() == k){
            list.push_back(curr);
            return;
        }
        
        for(int i=j;i<n;i++){
            curr += characters[i];
            backtrack(i+1,curr,characters,n,k);
            curr.erase(curr.length() - 1);
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        int n = characters.length(),k = combinationLength;
        string curr = "";
        backtrack(0,curr,characters,n,k);
    }
    
    string next() {
        return list[index++];
    }
    
    bool hasNext() {
        return (index<(int)list.size());
    }
};
