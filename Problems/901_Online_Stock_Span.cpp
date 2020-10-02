class StockSpanner {
public:
    stack<pair<int,int>> pw;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int w = 1;
        while(!pw.empty() && pw.top().first <= price){
            pair<int,int> temp = pw.top();
            pw.pop();
            w += temp.second;
        }
        pw.push({price,w});
        return w;
    }
};
