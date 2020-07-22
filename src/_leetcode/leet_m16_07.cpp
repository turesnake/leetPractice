/*
 * ====================== leet_m16_07.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m16_07 {//~


// 数学法:
// 两数最大值，为
// (abs(a-b) + a + b)/2


//  100%  100%
class S{
public:
    int maximum(int a, int b) {

        int64_t A=a;
        int64_t B=b;
        return (std::abs(A-B)+A+B)/2;

        
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: m16_07 :end ~~~~\n" );
}
}//~
