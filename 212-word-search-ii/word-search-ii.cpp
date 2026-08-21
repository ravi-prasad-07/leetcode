typedef struct trie{
    trie* link[26];
    bool flag=false;
    string word="";

    bool contains(char ch){
        return link[ch-'a']!=nullptr;
    }
    void put(char ch, trie* newnode){
        link[ch-'a']=newnode;
    }
    trie* get(char ch){
        return link[ch-'a'];
    }
}trie;


class implement{
    public:
    trie* root;

    implement(){
        root=new trie();
    }
    void addword(string word){
        trie* node=root;
        for(int i=0; i<word.length(); i++){
            if(!node->contains(word[i])){
                node->put(word[i], new trie());
            }
            node=node->get(word[i]);
        }
        node->flag=true;
        node->word=word;
    }

    trie* getRoot(){
        return root;
    }
};

class Solution {
public:
    vector<string> result;

    void dfs(vector<vector<char>>& board, int i, int j, trie* node){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='#'){
            return;
        }
        char ch=board[i][j];
        if(!node->contains(ch)){
            return;
        }
        trie* next=node->get(ch);
        if(next->flag){
            result.push_back(next->word);
            next->flag=false;
        }
        board[i][j]='#';
        dfs(board, i+1, j, next);
        dfs(board, i-1, j, next);
        dfs(board, i, j+1, next);
        dfs(board, i, j-1, next);
        board[i][j]=ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        implement obj;
        for(string& w : words){
            obj.addword(w);
        }

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                dfs(board, i, j, obj.getRoot());
            }
        }

        return result;
    }
};