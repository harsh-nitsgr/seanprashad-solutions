//leetcode.com/problems/subsets
// The simple approach to this problem is backtracking 
// We will start from first element of the array and make two recurrsive calls
// First if we include that particular element and second not including that element
// When we have traversed through all elements we can just pust answer in an answer array and return it

class Solution {
public:
    vector<vector<int>>ans;

    void sub(vector<int>&nums,int l,vector<int>&subans){
        if(l==nums.size()){
            ans.push_back(subans);
            return;
        }
        sub(nums,l+1,subans);
        subans.push_back(nums[l]);
        sub(nums,l+1,subans);
        subans.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subans;
        sub(nums,0,subans);
        return ans;
    }
};

// TC:O(2^n)
