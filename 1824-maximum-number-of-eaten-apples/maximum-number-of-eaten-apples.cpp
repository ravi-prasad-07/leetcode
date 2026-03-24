class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int d=1;
        int ans=0;

        priority_queue<pair<int,int>> q;
        int i=0;
        while(i<apples.size() || !q.empty()){
            if(i<apples.size()){
                q.push({-(d+days[i]),apples[i]});
            }
            i++;

            while(!q.empty() && -q.top().first<=d){
                q.pop();
            }

            if(q.size()){
                auto a=q.top();
                q.pop();
                a.second--;
                ans++;
                if(a.second>0){
                    q.push(a);
                }
            }
            
            d++;
        }

        return ans;
    }
};