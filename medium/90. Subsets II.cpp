// leetcode.com/problems/subsets-ii
// This question is quite similar to subsets-i
// Here to avoid duplicates we will sort the array and will exclude them in second recurssion call
// The recurssion tree will look like this

//                                      [1,2,2,3]
//                                       /     \
//                                      /       \
//                                   [1]          []
//                                   / \          /  \
//                              [1,2]   [1]      [2]   []
//                              / \     / \       / \  / \
//                            /    \  [1,3][1]   /   \ [3][]    --> Here we skipped the repeating number in our second recurrsion call
//                       [1,2,2] [1,2]        [2,2] [2]

class Solution {
public:
    vector<vector<int>>ans;
    void sub(vector<int>&nums,int l,vector<int>&subans){
        if(l==nums.size()){
            ans.push_back(subans);
            return;
        }
        subans.push_back(nums[l]);
        sub(nums,l+1,subans);
        subans.pop_back();
        while(l+1<nums.size() && nums[l]==nums[l+1])l++;
        sub(nums,l+1,subans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>subans;
        sub(nums,0,subans);
        return ans;
    }
};

// TC:O(n*2^n) -->every recusive call is having 2 recursive calls
