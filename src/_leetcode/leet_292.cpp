/*
 * ====================== leet_292.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 292. Nim 游戏
 */
#include "innLeet.h"

#include "ListNode.h"


namespace leet_292 {//~


// 从 1开始递推出规律
// 提示已经给出了，[1,3]先手必胜，4先手必输的规律


class S{
public:
    bool canWinNim( int n){

        if(n<0){ return true; }
        if(n==0){ return false; }
        return n%4!=0;
    }
};






//=========================================================//
void main_(){

    
    


    debug::log( "\n~~~~ leet: 292 :end ~~~~\n" );
}
}//~

