class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if(image[sr][sc]==color){
            return image;
        }

        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int num=image[sr][sc];
        image[sr][sc]=color;

        while(!q.empty()){
            int nsr=q.front().first;
            int nsc=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nnsr=nsr+dir[i][0];
                int nnsc=nsc+dir[i][1];

                if(nnsr>=0 && nnsr<image.size() && nnsc>=0 && nnsc<image[0].size() && image[nnsr][nnsc]==num){
                    image[nnsr][nnsc]=color;
                    q.push({nnsr,nnsc});
                }
            }
        }

        return image;
    }
};