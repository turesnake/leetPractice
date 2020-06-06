/*
 * ====================== leet_LCP_06.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * LCP 06. 拿硬币
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_LCP_06 {//~


// 100% 100%
class S{
public:
    // 1 <= len <= 4
    // 1 <= coins[i] <= 10
    int minCount( std::vector<int>& coins ){

        int out = 0;
        for( int i : coins ){
            out += (i+1)/2;
        }   
        return out;
    }
};





//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: LCP_06 :end ~~~~\n" );
}
}//~
