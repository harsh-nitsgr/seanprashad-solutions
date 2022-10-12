// This is also a standard backtracking question
// Keep swapping form staring index to end index
// The recursion tree will look like this
// 
//                                 [1,2,3]
//                                 /   |  \
//                                /    |   \
//                               /     |    \
//                         [1,2,3]  [2,1,3]  [3,2,1]   --> Starting index is zero
//                          /  \     /   \    /  \ 
//                         /    [2,1,3] [2,3,1]   \
//                        /       \         /      \      --> Starting index is one
//                    [1,2,3] [1,3,2]  [3,2,1]   [3,1,2]
//                       |       |        |         |          
//                    [1,2,3] [1,3,2]  [3,2,1]   [3,1,2]      --> Starting index two no change

class Solution {
public:
    vector<vector<int>>ans;

    void recurr(vector<int>&nums,int s){
        if(s==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=s;i<nums.size();i++){
            swap(nums[i],nums[s]);
            recurr(nums,s+1);
            swap(nums[i],nums[s]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        recurr(nums,0);
        return ans;
    }
};

// Another way of doing the same can be
// The recursion tree will look like this for [1,2,3]
// Here I am pushing new element at each place of previous element
//                            
//                                       [1]
//                                       /  \
//                                     /      \
//                                 [2,1]        [1,2]
//                                /  |  \       /  |  \
//                              /    |   \ [3,1,2][1,3,2][1,2,3]
//                       [3,2,1] [2,3,1][2,1,3]

class Solution {
public:
    vector<vector<int>>ans;

    void recurr(vector<int>&nums,int s,vector<int>&subans){
        if(s==0) subans.push_back(nums[s]),s++;
        if(s==nums.size()){
            ans.push_back(subans);
            return;
        }
        for(int i=0;i<subans.size()+1;i++){
            vector<int>temp=subans;
            subans.insert(subans.begin()+i,nums[s]);
            recurr(nums,s+1,subans);
            subans=temp;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>subans;
        recurr(nums,0,subans);
        return ans;
    }
};
