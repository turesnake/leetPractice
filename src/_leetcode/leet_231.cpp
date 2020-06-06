/*
 * ====================== leet_231.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 231. 2的幂
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_231 {//~


// 100%, 100%
class S{
public:
    bool isPowerOfTwo(int n) {
        if(n<1){ return false; }
        return n-(n&(-n))==0 ;
    }
};


//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 231 :end ~~~~\n" );
}
}//~
