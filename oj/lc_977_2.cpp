#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //双指针法
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size()-1;
        vector<int> result(nums.size(),0);
        for(int i = 0, j = nums.size()-1; i<=j;){
            if(nums[i]*nums[i] < nums[j]*nums[j]){
                result[k] = nums[j]*nums[j];
                k-=1;
                j-=1;
            }
            else{
                result[k] = nums[i]*nums[i];
                k-=1;
                i+=1;
            }
        }
        return result;
    }
};

int main(){

    return 0;
}