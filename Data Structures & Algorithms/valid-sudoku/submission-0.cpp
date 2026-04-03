class Solution {
public:
    bool validateRow(vector<vector<char>>& board,int row){
        unordered_map<char,int>r1;
        for(int i=0; i<9; i++){
            if(board[row][i]!='.')r1[board[row][i]]++;
        }
        for(auto it:r1){
            if(it.second>1) return false;
        }
        return true;
    }
    bool validateCol(vector<vector<char>>& board,int col){
        unordered_map<char,int>r2;
        for(int i=0; i<9; i++){
            if(board[i][col]!='.') r2[board[i][col]]++;
        }
        for(auto it:r2){
            if(it.second>1) return false;
        }
        return true;
    }
    bool validateSqaure(vector<vector<char>>& board,int row,int col){
        unordered_map<char,int>r3;
        for(int i=row; i<3+row; i++){
            for(int j=col; j<3+col; j++){
                if(board[i][j]!='.') r3[board[i][j]]++;
            }
        }
        for(auto it:r3){
            if(it.second>1) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool r;
        bool c;
        bool b;
        for(int i=0; i<9; i++){
            if(!validateRow(board,i)) return false;
        }
        for(int i=0; i<9; i++){
            if(!validateCol(board,i)) return false;
        }

        for(int i=0; i<9; i=i+3){
            for(int j=0; j<9; j=j+3){
                if(!validateSqaure(board,i,j)) return false;
            }
        }

        return true;
    }
};
