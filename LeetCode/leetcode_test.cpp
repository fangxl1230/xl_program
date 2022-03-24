#include "leetcode_test.h"
#include "tool/tool.h"
#include "leetcode_001-020.h"
#include <vector>

#include <iostream>
namespace {
const int space = 8;
}

void LeetCodeTest::Test001() {
    std::cout << "LeetCodeTest::Test001" << std::endl;

    std::vector<int> nums = {2,7,15,11};
    std::cout << "输入：";
    xl_tool::Tool::Printer(space, nums);

    int target = 13;
    std::cout << "目标：";
    xl_tool::Tool::Printer(space, std::to_string(target));

    std::vector<int> solution = xl_leetcode::LeetCode_001_020::twoSum(nums, target);
    std::cout << "输出：";
    xl_tool::Tool::Printer(space, solution);
}

void LeetCodeTest::Test012() {
    std::cout << "输入：" << "1003" << std::endl;
    std::cout << "输出：";
    xl_tool::Tool::Printer(space, xl_leetcode::LeetCode_001_020::intToRoman(1003));

    std::cout << "输入：" << "58" << std::endl;
    std::cout << "输出：";
    xl_tool::Tool::Printer(space, xl_leetcode::LeetCode_001_020::intToRoman(58));

    std::cout << "输入：" << "1994" << std::endl;
    std::cout << "输出：";
    xl_tool::Tool::Printer(space, xl_leetcode::LeetCode_001_020::intToRoman(1994));

}

void LeetCodeTest::Test013() {
    std::cout << "输入：" << "IX" << std::endl;
    std::cout << "输出：";
    xl_tool::Tool::Printer(space, std::to_string(xl_leetcode::LeetCode_001_020::romanToInt("IX")));
    std::cout << "输入：" << "MCMXCIV" << std::endl;
    std::cout << "输出：";
    int solution = xl_leetcode::LeetCode_001_020::romanToInt("MCMXCIV");
    xl_tool::Tool::Printer(space, std::to_string(solution));
}
