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

class WordDictionary {
public:
    node* root;

    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* newnode = root;
        for (int i = 0; i < word.length(); i++) {
            if (!newnode->contains(word[i])) {
                newnode->put(word[i], new node());
            }
            newnode = newnode->get(word[i]);
        }
        newnode->setEnd();        
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

private:
    bool searchHelper(const string& word, int idx, node* newnode) {
        if (newnode == NULL) return false;
        if (idx == word.length()) return newnode->isEnd();

        char ch = word[idx];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (newnode->links[i] != NULL) {
                    if (searchHelper(word, idx + 1, newnode->links[i])) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            if (!newnode->contains(ch)) return false;
            return searchHelper(word, idx + 1, newnode->get(ch));
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */