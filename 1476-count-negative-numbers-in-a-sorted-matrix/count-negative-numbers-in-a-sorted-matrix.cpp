class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        int row=0;
        int col=grid[0].size()-1;

        while(row<grid.size() && col>=0){
            if(grid[row][col]<0){
                cnt+=(grid.size() - row);
                col--;
            }
            else{
                row++;
            }
        }

        return cnt;
    }
};