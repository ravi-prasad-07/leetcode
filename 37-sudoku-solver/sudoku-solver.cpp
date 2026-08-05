class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board, int row, int col, char c) {

        for(int i=0; i<9; i++){
            if(board[row][i]==c){
                return false;
            }
            if(board[i][col]==c){
                return false;
            }

            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c){
                return false;
            }
        }

        return true; 
    }

    bool solve(vector<vector<char>>& board){

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(int ch='1'; ch<='9'; ch++){
                        if(isValidSudoku(board, i, j, ch)){
                            board[i][j]=ch;

                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
    }
};