typedef struct node{
    node *links[26];
    bool flag=false;
    bool contains(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, node* newnode){
        links[ch-'a']=newnode;

    }
    node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
}node;

class Trie {
private:
    node* root;
public:
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* newnode=root;
        for(int i=0; i<word.length(); i++){
            if(!newnode->contains(word[i])){
                newnode->put(word[i], new node());
            }
            newnode=newnode->get(word[i]);
        }

        newnode->setEnd();
    }
    
    bool search(string word) {
        node* newnode=root;
        for(int i=0; i<word.length(); i++){
            if(!newnode->contains(word[i])){
                return false;
            }

            newnode=newnode->get(word[i]);
        }

        return newnode->isEnd();
    }
    
    bool startsWith(string prefix) {
        node* newnode=root;
        for(int i=0; i<prefix.length(); i++){
            if(!newnode->contains(prefix[i])){
                return false;
            }
            newnode=newnode->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */