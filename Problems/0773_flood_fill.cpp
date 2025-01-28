class Solution {
public:
    void fillneighbour(vector<vector<int>>& img,int i,int j,int nclr,int cclr,vector<vector<int>>vis){
        vis[i][j] = 1;
        if(img[i][j] == cclr){
            img[i][j] = nclr;
        }else{
            return;
        }
        if((i-1) >= 0 && vis[i-1][j] == 0){
            fillneighbour(img,i-1,j,nclr,cclr,vis);
        }
        if((i+1) < img.size() && vis[i+1][j] == 0){
            fillneighbour(img,i+1,j,nclr,cclr,vis);
        }
        if((j-1) >= 0 && vis[i][j-1] == 0){
            fillneighbour(img,i,j-1,nclr,cclr,vis);
        }
        if((j+1) < img[0].size() && vis[i][j+1] == 0){
            fillneighbour(img,i,j+1,nclr,cclr,vis);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor){
            return image;
        }
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size()));
        fillneighbour(image,sr,sc,newColor,image[sr][sc],visited);
        return image;
    }
};