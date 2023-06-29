class Solution {
public:
    int findMin(vector<int>& nums) {

        int leftIndex = nums.size()/2, rightIndex = nums.size()/2;
        if(nums.size() == 1) return nums[0];
        else if( nums.size() == 2) return nums[0]>nums[1]?nums[1]:nums[0];
        else{
            if(nums.size() %2 == 0) // EVEN
            {
                while(true){

                    if(nums[leftIndex-1] > nums[leftIndex])
                        return nums[leftIndex] ;

                    if(nums[rightIndex+1] < nums[rightIndex])
                        return nums[rightIndex + 1];

                    leftIndex--;
                    rightIndex++;

                    if(rightIndex == nums.size()-1) rightIndex--;
                    if(leftIndex == 0) return nums[leftIndex];
                     
                }
            }
            else{
                while(true){

                    if(nums[leftIndex-1] > nums[leftIndex])
                        return nums[leftIndex] ;

                    if(nums[rightIndex+1] < nums[rightIndex])
                        return nums[rightIndex + 1];

                    leftIndex--;
                    rightIndex++;
                    if(leftIndex == 0 || rightIndex == nums.size()-1) break;
                     
                }
                return min(nums[0],nums[nums.size()-1]);
                }
    }
    }
};