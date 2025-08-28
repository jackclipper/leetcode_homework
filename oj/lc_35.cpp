#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nums_test;
    int target_test;

    //传值函数
    void set(vector<int>& nums,int target){
        nums_test = nums;
        target_test = target;
    }
    
    //主要函数
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int middle = (left+right)/2;
            if(nums[middle] < target){
                left = middle+1;
                continue;
            }
            else if(nums[middle] > target){
                right = middle-1;
                continue;
            }
            else{
                return middle;
            }
        }
        return right+1;    
    }
};

int main(){
    vector<int> nums1 = {1,3,5,6};
    int target1 = 0;

    Solution test;
    test.set(nums1, target1);
    int test_result = test.searchInsert(nums1,target1);
    cout << test_result <<endl;
    return 0;
}