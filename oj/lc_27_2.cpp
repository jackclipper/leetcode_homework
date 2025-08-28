#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int SlowIndex = 0;
        for(int FastIndex = 0; FastIndex < nums.size(); FastIndex++){
            if(nums[FastIndex] != val){
                nums[SlowIndex++] = nums[FastIndex];
            }
        }
        return SlowIndex;
    }
};


int main(){
    
    return 0;
}