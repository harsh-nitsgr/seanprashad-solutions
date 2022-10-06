//Take product of all the numbers except zero
//now if there are more than one zeros then obviously the whole array will become zero
//if there is only one zero then only one number will be non-zero which will be product of all
//else there is no zero could be written directly be deviding the product by each number

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros=0,neg=0,prod=1,n=nums.size();
        for(auto&num:nums){
            if(num<0)neg++;
            if(num!=0)prod*=num;
            else zeros++;
        }
        vector<int>ans(n,0);
        if(zeros==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0)ans[i]=prod;
            }
        }
        else if(zeros==0){
            for(int i=0;i<n;i++){
                ans[i]=prod/nums[i];
            }
        }
        return ans;
    }
};
//TC:O(n)

//Using prefix product and suffix product
//In prefix product find product of all numbers left of that particular number(the number itself not included)
//In suffix product find product of all numbers right of that particular number(the number itself not included)
//Then take product of prefix and suffix

class Solution {
public:        
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> vRes(n, 1);
        int prefixProd = 1;
        for (int i = 0; i < n; i++) {
            vRes[i] = prefixProd;
            prefixProd *= nums[i];
        }
        int suffixProd = 1;
        for (int i = n - 1; i >= 0; i--) {
            vRes[i] *= suffixProd;
            suffixProd *= nums[i];
        }
        return vRes;
    }
  //TC:O(n)

};
