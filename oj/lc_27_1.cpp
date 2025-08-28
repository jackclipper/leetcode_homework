#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int result_size = nums.size();
        for(int i = 0; i < result_size; i++){
            if(nums[i] == val){
                for(int j = i; j+1 < result_size; j++){
                    nums[j] = nums[j+1];
                }
                result_size -= 1;
                i--; //下标移动
            }
        }
        return result_size;
    }
};


int main(){
    
    return 0;
}