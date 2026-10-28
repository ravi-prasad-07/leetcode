typedef struct node{
    int key;
    int val;

    node *prev;
    node *next;

    node(int k, int v){
        key=k;
        val=v;

        prev=nullptr;
        next=nullptr;
    }

}node;

class LRUCache {
private:

    int capacity;
    unordered_map<int, node*> ump;
    node* head=new node(-1, -1);
    node* tail=new node(-1, -1);

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }

    ~LRUCache(){
        node* curr=head;

        while(curr!=nullptr){
            node* temp=curr;
            curr=curr->next;

            delete temp;
        }
    }
    
    int get(int key) {
        if(ump.count(key)){
            node* nd=ump[key];
            int res=nd->val;

            del(nd);
            addNode(nd);

            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(capacity==0){
            return;
        }
        
        if(ump.count(key)){
            node* nd=ump[key];
            nd->val=value;

            del(nd);
            addNode(nd);
        }
        else{
            if(ump.size()==capacity){
                node* nd=tail->prev;

                del(nd);
                ump.erase(nd->key);

                delete nd;
            }

            node* nd=new node(key, value);
            addNode(nd);
            ump[key]=nd;
        }
    }

    void addNode(node* nd){
        node* temp=head->next;
        
        nd->next=temp;
        nd->prev=head;

        head->next=nd;
        temp->prev=nd;
    }

    void del(node* nd){
        node* pre=nd->prev;
        node* nex=nd->next;

        pre->next=nex;
        nex->prev=pre;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */