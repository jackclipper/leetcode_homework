#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = __INT32_MAX__; // 指令代替手写数字
        int sum = 0;                // 总和
        int i = 0;                  // 滑动窗口起始点
        int sublength = 0;          // 滑动窗口长度
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                sublength = (j - i + 1);
                result = sublength < result ? sublength : result; // 三元表达式写法，如果true执行前面的，如果false执行后面的
                sum -= nums[i++];                                 // 每次变化都要检查哪些变量需要更改
            }
        }
        return result == __INT32_MAX__ ? 0 : result;
    }
};

int main()
{

    return 0;
}