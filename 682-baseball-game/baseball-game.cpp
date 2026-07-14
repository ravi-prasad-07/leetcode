class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;

        for(int i=0; i<operations.size(); i++){
            if(operations[i]=="C"){
                s.pop();
            }
            else if(operations[i]=="D"){
                int x=s.top();
                s.push(x*2);
            }
            else if(operations[i]=="+"){
                int prev1=s.top();
                s.pop();
                int prev2=s.top();
                s.pop();

                s.push(prev2);
                s.push(prev1);

                s.push(prev1+prev2);
            }
            else{
                s.push(stoi(operations[i]));
            }
        }

        int sum=0;
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }

        return sum;
    }
};