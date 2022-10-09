//leetcode.com/problems/longest-consecutive-sequence

// 1) First simple approach can be using sorting
// 2) Sort the array and keep track of next number is consecutive or not
// 3) If yes increase the current length by one 
// 4) If next and current numbers are same just skip that number because that is not going to increase the size of consecutive elements
// 5) Keep storing the maximum of current lenght in a variable and return that

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())return 0;
        sort(nums.begin(),nums.end());
        int curr=1,fin=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1)curr++;
            else if(nums[i+1]==nums[i])continue;
            else curr=1;
            fin=max(fin,curr);
        }
        return fin;
    }
};

//TC:O(n log(n))

// Using hashmap
// 1) Insert all numbers in a Unordered_set
// 2) Now traverse through array
// 3) Now keep finding the consecutive number in the set and store the maximum length.
// 4) A simple optimisation which will make this algo form O(n^2) to O(n) is --
// 5) We can put a check if previous number of any number is already present in the set or not.
// 6) If the previous number is present then we know that number will give the larger length.
// 7) So we won't find the lenth from current number.
// 8) For example 1,2,3,4,5 all are present in the array.
//    So we need not the search length of consecutive elements starting form 2 or 3 or 4 or 5 because
//    we know that the number starting form 1 will give the longest length.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())return 0;
        unordered_set<int>set;

        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        int final=1;
        for(int i=0;i<nums.size();i++){
            if(set.find(nums[i]-1)==set.end()){
                int current=1,num=nums[i];
                while(set.find(num+1)!=set.end()){
                    current++;
                    num++;
                }
                final=max(final,current);
            }
        }
        return final;
    }
};

// TC:O(n)
