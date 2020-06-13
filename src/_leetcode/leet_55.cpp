/*
 * ====================== leet_55.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 55. 跳跃游戏
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_55 {//~


// 反向查找 “能达到的最远端”  34%  8%
class S{
public:
    // 元素非负
    bool canJump( std::vector<int>& nums ){

        if(nums.empty()){ return false; }
        int N = static_cast<int>(nums.size());
        int lst = N-1;
        int i=N-2;
        for( ; i>=0; i-- ){
            if( i+nums.at(i) >= lst ){
                lst = i;
            }
        }
        return lst==0;
    }
};


//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 55 :end ~~~~\n" );
}
}//~
