/*
 * ====================== leet_m16_01.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 16.01. 交换数字
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m16_01 {//~



// 原地交换 元素 45%, 100%
// 用加法会溢出，换用减法
class S{
public:
    // 只有 2个元素
    std::vector<int> swapNumbers(std::vector<int>& numbers) {
        numbers.at(0) = numbers.at(0) - numbers.at(1);//[0]=off
        numbers.at(1) = numbers.at(0) + numbers.at(1);//[2]=a
        numbers.at(0) = numbers.at(1) - numbers.at(0);
        return numbers;
    }
};



//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: m16_01 :end ~~~~\n" );
}
}//~
