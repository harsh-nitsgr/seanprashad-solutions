//https://leetcode.com/problems/set-matrix-zeroes

//Take two unoreded sets each for row and column.
//if a zero is found in any row push row in set
//if a zero is found in any col push col in set
//now traverse through whole matrix and if any of row or col is zero then make element zero

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix){
        int n=matrix.size(),m=matrix[0].size();
        unordered_set<int>row,col;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row.find(i)!=row.end() || col.find(j)!=col.end()){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

// A better memory optimisation can be done if we use first row and first col as the indication of zero row or col
// basically using first row and first col instead of set
// Make first row element as zero corresponding to the zero in any row same with column
// Now don't touch first col as it will affect our stored data there rather make saperate variable for it.
// The same with row we can traverse starting from bottom so that first row is not affected
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();

        bool col0=false;
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0)col0=true;
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=1;j--){
                if(matrix[0][j]==0 or matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
            if(col0)matrix[i][0]=0;
        }
        
    }
};
