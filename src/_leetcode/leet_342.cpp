/*
 * ====================== leet_342.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 342. 4的幂
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_342 {//~


// 判断数 是否为 4 的 N 次方
// 4 : 100b
// 16: 100 00b
// 64: 100 00 00b
// 二进制表达，一定是一个1，加很多组 00
class S{
public:
    bool isPowerOfFour(int num){

        if( num < 0 ){ return false; } // 非负
        int lowBit = num&(-num);
        if( num-lowBit!=0 ){ return false; } // 检查 二进制表达中，只有头部一个 1
        // 现在剩下两种情况，要么是 1 后面加 偶数个 0（符合）
        // 要么是后面加 奇数个0，（不符合）
        return num%3==1; 
    }
};




//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: 342 :end ~~~~\n" );
}
}//~
