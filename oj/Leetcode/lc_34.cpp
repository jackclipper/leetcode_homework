#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> nums_test;
    int target_test;

    void set(vector<int>& nums,int target){
        nums_test = nums;
        target_test = target;
    }

    //函数部分
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int nums_ends = nums.size()-1;
        bool FIND = false;
        vector<int> result(2);
        //先找左边界
        while(left <= right){
            int middle = (right+left)/2;
            if(nums[middle] < target){
                left = middle+1;
                continue;
            }
            else if(nums[middle] > target){
                right = middle-1;
                continue;
            }
            else{
                FIND = true;
                if(middle == 0){
                    result[0] = 0;
                    break;
                }
                else if(nums[middle-1] == target){
                    right = middle-1;
                    continue;
                }
                else{
                    result[0] = middle;
                    break;
                }
            }
        }
        //再找右边界
        left = 0;
        right = nums.size()-1;
        while(left <= right){
            int middle = (right+left)/2;
            if(nums[middle] < target){
                left = middle+1;
                continue;
            }
            else if(nums[middle] > target){
                right = middle-1;
                continue;
            }
            else{
                FIND = true;
                if(middle == nums_ends){
                    result[1] = nums_ends;
                    break;
                }
                else if(nums[middle+1] == target){
                    left = middle+1;
                    continue;
                }
                else{
                    result[1] = middle;
                    break;
                }
            }
        }
        if (FIND == false){
            return {-1,-1};
        }
        return result;
    }
};

int main(){
    vector<int> nums1 = {5,7,7,8,8,10};
    int target1 = 8;
    Solution result;
    result.set(nums1,target1);
    vector<int> result_output = result.searchRange(result.nums_test,result.target_test);
    cout <<result_output[0] <<' ' <<result_output[1];
    return 0;
}