//leetcode.com/problems/find-the-duplicate-number

//By modifying the array itself
//Use number as indices of the array
//Every visited number will be marked as negative
//Whenever the same number occurs twice its will indicate the same location.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto &num:nums){
            if(nums[abs(num)-1]>0)nums[abs(num)-1]=-(nums[abs(num)-1]);
            else return abs(num);
        }
        return INT_MAX;
    }
};
//TC:O(n)

//We can use floyed's algorithm as well
//It says if a number occurs twice it will work as a loop if we use numbers as the indices fast and slow pointers will works same as in linked list.
//fast pointer will move twice the speed of slow pointer.
//if there is any repeated number creating the loop it will meet somewhere.
//Now by flowed's algo we will take one pointer to start and move both with equal speed whenever they meet is the number repeating

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //using floyd's algorithm
        int slow=nums[0],fast=nums[0];
        
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(fast!=slow);
        
        fast=nums[0];
        while(fast!=slow){
            fast=nums[fast];
            slow=nums[slow];
        }
        return fast;   
    }
};
//TC:O(n)
