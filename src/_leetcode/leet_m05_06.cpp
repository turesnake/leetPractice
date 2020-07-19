/*
 * ====================== leet_m05_06.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 05.06. 整数转换
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m05_06 {//~


// 参数可能是负数，最好改成 无符号int 来操作

// 100% 100%
class S{
public:
    int convertInteger( int A, int B ){

        uint32_t x = static_cast<uint32_t>(A^B);
        int num = 0;
        for(; x!=0; num++ ){
            x -= x&(-x);
        }
        return num;


    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: m05_06 :end ~~~~\n" );
}
}//~
