//leetcode.com/problems/target-sum/
// This problem can be solved using backtracking and dynamic programming

// Here is backtracking solution.
// For each index we choose two possibilities either add that num or subtract.
// When we reach to final index see whether sum is equal to target or not.
// If yes then add one to ans and return final answer.
//  
//                                            [1,2,1,1]
//                                               
//                                                0
//                                            /      \
//                                          /          \
//                                        1             - 1
//                                     /    \            /   \
//                                   3      -1         1       -3
//                                 /  \    /  \       /  \     /    \ 
//                               2    4   -2   0      0    2  -4     -2
//                              /\   /\   /\   /\    / \   /\   /\    / \
//                             1 3  3 5 -3 -1 -1 1  -1 1  1 3 -5 -3  -3  -1


class Solution {
public:
    void findTarget(vector<int>&nums,int &target,int &ans,int sum,int idx){
        if(idx==nums.size()){
            if(sum==target)ans++;
            return;
        }
        findTarget(nums,target,ans,sum+nums[idx],idx+1);
        findTarget(nums,target,ans,sum-nums[idx],idx+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0,sum=0;
        findTarget(nums,target,ans,sum,0);
        return ans;
    }
};

// TC:O(n*2^n)

// Here is dynamic programming solution
// As we can see in above recurssion tree there are many repeating subproblems which clicks the idea of dynamic programming
// We are creating two maps to store occurance of elements at each step of recursion tree.

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>dp;
        dp[nums[0]]++,dp[-nums[0]]++;
        for(int i=1;i<nums.size();i++){  
            unordered_map<int,int>dp1;
            for(auto&it:dp){
                dp1[it.first-nums[i]]+=it.second;
                dp1[it.first+nums[i]]+=it.second;
            }
            dp=dp1;
        }
        return dp[target];
    }
};
// TC:O(n*2^n - time for repeating subproblems)
