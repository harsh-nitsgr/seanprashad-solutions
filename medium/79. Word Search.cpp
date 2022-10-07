//leetcode.com/problems/word-search

// This is standard backtracking problem
// First find the starting word of the given string 
// Apply dfs through this
// Here we are using our board itself as the visited matrix
// Keep changing the visited charector to any char other than alphabets this will indicate that the char is already visited
// Now traverse in all possible directions
// Any direction which leads out of board will not give the answer so return false.
// Now after compleating dfs board will be restored for next iteration

class Solution {
private:
    bool dfs(vector<vector<char>>& board, string &word,int i, int j,int count){
        int n=board.size(), m=board[0].size();
        if(count==word.size())
            return true;
        if(i<0 or j<0 or i>n-1 or j>m-1 or word[count]!=board[i][j])
            return false;
        int c=board[i][j];
        board[i][j]='&';
        bool ret= dfs(board,word,i-1,j,count+1)
                ||dfs(board,word,i+1,j,count+1)
                ||dfs(board,word,i,j-1,count+1)
                ||dfs(board,word,i,j+1,count+1);
        board[i][j]=c;
        return ret;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] and dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};
