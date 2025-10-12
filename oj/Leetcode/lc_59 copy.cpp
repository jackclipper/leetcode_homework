#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        vector<int> now_place = {0,0}; // 下一步坐标
        bool right = true, left = false, up = false, down = false; // 下一步该往哪里走
        int change_counter = 0; // 方向变了几次了，4次后max_step-2，change_counter归零
        int now_step = 0; // 这个方向的第几步，达到最大步数后要下一步的坐标（方向），同时归为1
        int max_step = n-1; // 这个方向的最大步数
        for (int now_num = 1; now_num <= n*n; now_num++){
            result [now_place[0]] [now_place[1]] = now_num;
            // 以下用于解决下一步方向和坐标的问题
            if(now_step == max_step){
                change_counter += 1;
                now_step = 0;
                if(right == true){
                    right = false;
                    down = true;
                    now_place = {now_place[0]+1, now_place[1]};
                }
                else if(down == true){
                    down = false;
                    left = true;
                    now_place = {now_place[0], now_place[1]-1};
                }
                else if(left == true){
                    left = false;
                    up = true;
                    now_place = {now_place[0]-1, now_place[1]};
                }
                else{
                    up = false;
                    right = true;
                    now_place = {now_place[0], now_place[1]+1};
                }
            }
            else{
                if(right == true){
                    now_place = {now_place[0], now_place[1]+1};
                }
                else if(down == true){
                    now_place = {now_place[0]+1, now_place[1]};
                }
                else if(left == true){
                    now_place = {now_place[0], now_place[1]-1};
                }
                else{
                    now_place = {now_place[0]-1, now_place[1]};
                }
            }
            now_step += 1;
            //以下用于解决方向变了4次之后max_step的问题
            if(change_counter == 3){
                change_counter = 0;
                max_step -= 2;
            }
        }
        return result;
    }
};

int main(){

    return 0;
}