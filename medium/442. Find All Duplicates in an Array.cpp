//leetcode.com/problems/find-all-duplicates-in-an-array

//Use numbers as indices itself
//keep marking the visited numbers by assing negative sign to them
//whenever a negative number occurs it means it was visited previously so put them in a vector and return.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]>0)nums[abs(nums[i])-1]*=-1;
            else ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};

//TC:O(n)
