//can be solved using sorting and hashmap
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return 1;
            }
        }
        return 0;
    }
};

//TC:O(nlog(n))

//using hashmap
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>set;
        for(auto&it:nums){
            if(set.find(it)!=set.end())return true;
            set.insert(it);
        }
        return false;
    }
};

//TC:O(n)
