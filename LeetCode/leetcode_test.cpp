#include "leetcode_test.h"
#include "tool/tool.h"
#include "leetcode_001-020.h"
#include <vector>
#include <math.h>
#include <string.h>
#include <locale>
//#include <stdio.h>
#include <iomanip>

#include <iostream>
namespace {
const int space = 8;
}
void LeetCodeTest::Test() {
//    Test001();
//    Test012();
//    Test013();
//    std::string a = "16";
//    xl_tool::Tool::Printer(space, xl_tool::ConvertTool::ConvertToAnybit(a, 10, 16));
//    xl_tool::Tool::Printer(space, xl_tool::ConvertTool::ConvertToAnybit(a, 16, 16));
    double a = -1.3, b = 1.3;

    std::cout << std::setw(space) << "floor: " << std::setw(4) << a << ": " << floor(a) << std::setw(4) << b << ": "<< floor(b) << std::endl;
    std::cout << std::setw(space) << "ceil: "  << std::setw(4) << a << ": " << ceil(a)  << std::setw(4) << b << ": "<< ceil(b)<< std::endl;
    std::cout << std::setw(space) << "round: " << std::setw(4) << a << ": " << round(a) << std::setw(4) << b << ": "<< floor(b) << std::endl;
    std::cout << std::setw(space) << "7/2: " << std::setw(4) << 7/2 << std::setw(4) << "-7/2: " << std::setw(4) << -7/2<< std::endl;
    std::cout << std::setw(space) << "7%2: " << std::setw(4) << 7%2 << std::setw(4) << "-7%2: " << std::setw(4) << -7%2<< std::endl;
    std::cout << std::setw(space) << "-12.3: " << std::setw(4) << fabs(-12)
              << std::setw(4) << "-24.5: " << std::setw(4) << abs(-24.5) << std::endl;
    std::cout << std::setw(space) << "pow(4,3): " << std::setw(4) << pow(4,3) << std::endl;

}


//�ַ���תʮ������
void StrToHex(char* pbDest, char* pbSrc, int nLen) {
    char h1, h2;
    char s1, s2;

//    for (int i = 0; i < nLen; i++) {

//    }

    for(int i=0; i < nLen / 2; i++) {
        h1 = pbSrc[2 * i];
        h2 = pbSrc[2 * i + 1];

        char x = toupper(h1);
        s1 = toupper(h1) - 0x30; //toupper ת��Ϊ��д��ĸ
        if (s1 > 9) {
            s1 -= 7;
        }
        char y = toupper(h2);
        s2 = toupper(h2) - 0x30;
        if (s2 > 9) {
            s2 -= 7;
        }
        char z = s1 * 16 + s2;
        pbDest[i] = s1 * 16 + s2;
    }
}

//ʮ������ת�ַ���
void HexToStr(char *pszDest, char *pbSrc, int nLen) {
    char ddl, ddh;
    for(int i = 0; i < nLen; i++) {
        ddh = 48 + pbSrc[i] / 16;
        ddl = 48 + pbSrc[i] % 16;

        if (ddh > 57) {
            ddh = ddh + 7;
        }
        if (ddl > 57) {
            ddl = ddl + 7;
        }
        pszDest[i * 2] = ddh;
        pszDest[i * 2 + 1] = ddl;
    }
    pszDest[nLen * 2] = '\0';
}

void LeetCodeTest::Test2() {
    //�ַ���תʮ������
    char *dest = new char[4];
    char *src = "ccaa";
    StrToHex(dest, src, 4);

    std::cout << dest[0] << dest[1] << std::endl;

    char sr = 0xA2;
    HexToStr(src, dest, 4);
    int a = 0;
//    std::string hex_str = "0xc1";
//    int i��        intx
//    int v;
//    char bs[33];   result_b
//    char b[33];    bit
//    char hs[9];    result_h
//    char h[9];     hexx
//    char s[4];
//    char *e;       hex_c

    //ltoa����������ת���������ѳ�������ת��Ϊ������Ƶ��ַ����ĺ���
    //sprintf �����ַ�����ʽ������,�Ѹ�ʽ��������д��ĳ���ַ�����





    //�������ַ���ת��Ϊʮ�������ַ���
//    char result_b[33];
//    char result_h[33];
//    char hexx[33];
//    int intx;
//    char *hex_c;
//    strcpy(result_b, "00000000000000000000010000000000");
//    intx = strtol(result_b, &hex_c, 2);
//    ltoa(intx, hexx, 16);
//    sprintf(result_h, "%04s", hexx);
//    std::cout << "result_b " <<  result_b << " result_h " << result_h << std::endl;



//    // �������ַ���ת��Ϊʮ��������
//        strcpy(bs,"00000000000000000000010000000000");
//        i=strtol(bs,&e,2);
//        printf("bs=%s,i=%d\n",bs,i);
//    // ʮ�������ַ���ת�ɶ����ƴ�
//        strcpy(hs,"00000400");
//        sscanf(hs,"%x",&i);
//        ltoa(i,b,2);
//        sprintf(bs,"%032s",b);
//        printf("hs=%s,bs=%s\n",hs,bs);
//    // ASC\GBK�ַ���תʮ�����ƴ�
//        strcpy(s,"a��");
//        i=0;
//        while (1) {
//            if (0==s[i]) break;
//            sprintf(hs+i*2,"%02X",(unsigned char)s[i]);
//            i++;
//        }
//        setlocale(LC_ALL,"chs");
//        printf("s=%s,hs=%s\n",s,hs);
//    // ʮ�������ַ���ת�ɺ��֣�GBK�����ַ�(ASC)
//        strcpy(hs,"61BABA");
//        i=0;
//        while (1) {
//            if (1!=sscanf(hs+i*2,"%2x",&v)) break;
//            s[i]=(char)v;
//            i++;
//        }
//        s[i]=0;
//        printf("hs=%s,s=%s\n",hs,s);

//        return 0;

//    }

}

void LeetCodeTest::Test001() {
    std::cout << "LeetCodeTest::Test001" << std::endl;

    std::vector<int> nums = {2,7,15,11};
    std::cout << "���룺";
    xl_tool::Tool::Printer(space, nums);

    int target = 13;
    std::cout << "Ŀ�꣺";
    xl_tool::Tool::Printer(space, std::to_string(target));

    std::vector<int> solution = xl_leetcode::LeetCode_001_020::twoSum(nums, target);
    std::cout << "�����";
    xl_tool::Tool::Printer(space, solution);
}

void LeetCodeTest::Test012() {
    std::cout << "���룺" << "1003" << std::endl;
    std::cout << "�����";
    xl_tool::Tool::Printer(space, xl_leetcode::LeetCode_001_020::intToRoman(1003));

    std::cout << "���룺" << "58" << std::endl;
    std::cout << "�����";
    xl_tool::Tool::Printer(space, xl_leetcode::LeetCode_001_020::intToRoman(58));

    std::cout << "���룺" << "1994" << std::endl;
    std::cout << "�����";
    xl_tool::Tool::Printer(space, xl_leetcode::LeetCode_001_020::intToRoman(1994));

}

void LeetCodeTest::Test013() {
    std::cout << "���룺" << "IX" << std::endl;
    std::cout << "�����";
    xl_tool::Tool::Printer(space, std::to_string(xl_leetcode::LeetCode_001_020::romanToInt("IX")));
    std::cout << "���룺" << "MCMXCIV" << std::endl;
    std::cout << "�����";
    int solution = xl_leetcode::LeetCode_001_020::romanToInt("MCMXCIV");
    xl_tool::Tool::Printer(space, std::to_string(solution));
}
