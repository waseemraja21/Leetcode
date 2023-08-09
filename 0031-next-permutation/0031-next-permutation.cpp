class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // lets say given is {2, 4, 1, 7, 5, 0} its next permutation will be {2, 4, 5, 0, 1, 7}
        // so we travers from right end and check if currnt element is less than its right than it is breaking non increasing sequence we store its index and check for an element that is just greater than
        //     it, we will be searchig from right end bxz it has not increasing property so first element 
        //     that will be greater than it is required one
        //     we swap tow element 
        //     we reverse rest right to make it increasing bxz we are finding next greater
            
        int breakPoint = -1;
        int nextGreaterIndex = -1;
        
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                breakPoint = i;
                break;
            }
        }
        
        if(breakPoint == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i= nums.size()-1; i>breakPoint; i--){
            if(nums[i] > nums[breakPoint]){
                nextGreaterIndex = i;
                break;
            }
        }
        swap(nums[breakPoint], nums[nextGreaterIndex]);
        reverse(nums.begin()+breakPoint+1, nums.end());
        return;
        
    }
};