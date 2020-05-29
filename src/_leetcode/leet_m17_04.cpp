/*
 * ====================== leet_m17_04.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.04. 消失的数字
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_m17_04 {//~



int missingNumber( std::vector<int>& nums ){
    int N = static_cast<int>(nums.size());
    int sum = (N+1)*N/2;
    for( int i : nums ){
        sum -= i;
    }
    return sum;
}





//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: m17_04 :end ~~~~\n" );
}
}//~
