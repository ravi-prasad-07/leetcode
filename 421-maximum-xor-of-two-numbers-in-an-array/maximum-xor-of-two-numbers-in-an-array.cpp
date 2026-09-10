typedef struct node{
    node* link[2];

    bool contain(int bit){
        return link[bit]!=NULL;
    }
    void put(int bit, node* ls){
        link[bit]=ls;
    }
    node* get(int bit){
        return link[bit];
    }
}node;

class Trie{
    private:
        node* root;
    public:
        Trie(){
            root=new node();
        }

        void insert(int num){
            node* temp=root;

            for(int i=31; i>=0; i--){
                int bit=(num>>i)&1;
                if(!temp->contain(bit)){
                    temp->put(bit, new node());
                }
                temp=temp->get(bit);
            }
        }

        int getSol(int num){
            node* temp=root;
            int no=0;
            for(int i=31; i>=0; i--){
                int bit=(num>>i)&1;

                if(temp->contain(1-bit)){
                    no|=(1<<i);
                    temp=temp->get(1-bit);
                }
                else{
                    temp=temp->get(bit);
                }
            }

            return no;
        }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* obj=new Trie();

        for(auto it: nums){
            obj->insert(it);
        }

        int maxi=INT_MIN;
        for(auto it: nums){
            int temp=obj->getSol(it);
            maxi=max(maxi, temp);
        }

        return maxi;
    }
};