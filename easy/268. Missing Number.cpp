class Solution {
public:
  
  //using bit-mainpulation
  //just keep taking xor of each number and numbers from 1 to n to all others will be cancelled and only missing number will be left
  
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),a=0;
        for(int i=0;i<n;i++){
            a=a^i^nums[i];
        }
        return a^n;
    }
  //TC:O(n)
  
  //using sorting 
  //sort numbers and and see if next is 1 greater than previous
  
    int missingNumber(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(nums[0]!=0) return 0;  
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]!=1) return (nums[i]+1);
        }
        return (nums[n-1]+1);
    }
  //TC:O(n)

  //using math
  //get sum of all numbers and get differnce will sum of 1 to n using formula
        int sum=0,n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return (n*(n+1)/2)-sum;
        
  //TC:O(n)
};
