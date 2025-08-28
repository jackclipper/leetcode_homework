#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1||num==0){
            return true;
        }
        int left = 0;
        int right = num/2;
        while(left <= right){
            int middle = left+(right-left)/2; //防止溢出
            long long multiply = 1LL*middle*middle;
            if(multiply > num){
                right = middle-1;
            }
            else if(multiply < num){
                left = middle+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main(){

    return 0;
}