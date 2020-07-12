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


//  异或 交换法
//  38%   100%
class S2{
public:
    // 只有 2个元素
    std::vector<int> swapNumbers(std::vector<int>& numbers) {
        
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0];// [1] 成功变为 [0]
        numbers[0] ^= numbers[1];// [0] 成功变为 [1]
        return numbers;
    }
};



// 这是 记录最优解，但是它新建了 vector，似乎不符合题意

class S3{
public:
    // 只有 2个元素
    std::vector<int> swapNumbers(std::vector<int>& numbers) {
        return { numbers[1], numbers[0] };
    }
};



//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: m16_01 :end ~~~~\n" );
}
}//~
