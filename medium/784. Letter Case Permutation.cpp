//leetcode.com/problems/letter-case-permutation
//Here I am just storing the recurrsion tree in a vector 

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int a=0;
        for(auto&it:s)if(isalpha(it))a++;
        vector<string>ans[a+1];
        ans[0].push_back(s);
        int cnt=0;
        for(int i=1;i<a+1;i++){
            while(cnt<s.size()-1 && !isalpha(ans[0][0][cnt]))cnt++;

            for(int j=0;j<ans[i-1].size();j++){
                ans[i].push_back(ans[i-1][j]);
                if(isupper(ans[i-1][j][cnt]))
                    ans[i-1][j][cnt]=tolower(ans[i-1][j][cnt]);
                else if(islower(ans[i-1][j][cnt]))
                    ans[i-1][j][cnt]=toupper(ans[i-1][j][cnt]);
                ans[i].push_back(ans[i-1][j]);
            }
            cnt++;
        }
        return ans[a];
    }
};
// TC:O(2^n)

// Here is the recurrsive solution
// Calling recurssion everytime no matter it is a number or uppercase or lowercase
// If any char is alphabet so now again call recurrsion by changing upper to lower or lower to upper

class Solution {
public:
    void recurr(string &s,int i,vector<string>&res){
        if(i==s.size()){
            res.push_back(s);
            return;
        }
        recurr(s,i+1,res);
        if(isalpha(s[i])){
            if(islower(s[i])) s[i]=toupper(s[i]);
            else s[i]=tolower(s[i]);
            recurr(s,i+1,res);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        recurr(s,0,res);
        return res;
    }
};
// TC:O(2^n)
