/*
 * ====================== leet_m64.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题64. 求1+2+…+n
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m64 {//~



// 利用 逻辑运算符的短路特性，来做条件选择 
class S{
public:
    // 1 <= n <= 10000
    int sumNums( int n ){
        n && (n += sumNums(n-1));
        return n;
    }
};



// 还有一个方法是 快速乘
// 待学习...



//=========================================================//
void main_(){

    //cout<< S{}.work<4>() <<endl;

    debug::log( "\n~~~~ leet: m64 :end ~~~~\n" );
}
}//~
