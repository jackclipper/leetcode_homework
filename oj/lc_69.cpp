#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==1||x==0){
            return x;
        }
        int left = 0;
        int right = x/2;
        while(left <= right){
            int middle = left+(right-left)/2; //防止溢出
            long long multiply = 1LL*middle*middle;
            if(multiply > x){
                right = middle-1;
            }
            else if(multiply < x){
                left = middle+1;
            }
            else{
                return middle;
            }

        }
        return right;
    }
};

int main(){

    return 0;
}