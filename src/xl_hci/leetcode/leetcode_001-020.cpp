#include "leetcode_001-020.h"
namespace xl_leetcode {

//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
std::vector<int> LeetCode_001_020::twoSum(std::vector<int>& nums, int target) {
    std::vector<int> solution;
    solution.resize(2);
    unsigned num = nums.size();
    for (unsigned i = 0; i < num; i++) {
        for (unsigned j = i+1; j < num; j++) {
            if ((nums[i] + nums[j]) == target) {
                solution[0] = i;
                solution[1] = j;
            }
        }
    }
    return solution;
} //ok 202203102151


//罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
std::string LeetCode_001_020::intToRoman(int num) {
    std::string Roman = "";
    const std::pair<int, std::string> valueSymbols[] = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"},
    };

    for (const auto&[value, symbol] : valueSymbols) {
        while (num >= value) {
            num -= value;
            Roman += symbol;
        }
        if (num == 0) {
            break;
        }
    }
    return Roman;
}//ok 202203232151


//罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
//https://leetcode-cn.com/problems/roman-to-integer
int LeetCode_001_020::romanToInt(std::string s) {
    int count = 0;
    std::map<char, int> roma = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
    unsigned num = s.size();
    for (unsigned i = 0; i < num; i++) {
        int a = roma[s[i]];
        int b = roma[s[i+1]];
        if ((i < num - 1) && (a < b)) {
            count += (b - a);
            i++;
        }
        else {
            count += a;
        }
    }  
    return count;
}//ok 202203112151

} //namespace xl_leetcode
