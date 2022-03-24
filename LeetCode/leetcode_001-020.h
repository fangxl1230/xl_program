#ifndef LEETCODE_H
#define LEETCODE_H
#include <vector>
#include <string>
#include <map>
namespace xl_leetcode {
class LeetCode_001_020 {
public:
    LeetCode_001_020() = delete;

    //LeetCode_1.两数之和
    //https://leetcode-cn.com/problems/two-sum
    static std::vector<int> twoSum(std::vector<int>& nums, int target);

    //LeetCode_12.整数转罗马数字
    static std::string intToRoman(int num);



    //LeetCode_13.罗马数字转整数
    static int romanToInt(std::string s);
    static int romanToInt2(std::string s);

};

} //namespace xl_leetcode
#endif // LEETCODE_H
