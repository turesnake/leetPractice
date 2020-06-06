/*
 * ====================== leet_217.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 217. 存在重复元素
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_217 {//~


// 55%, 5%
class S{
public:
    bool containsDuplicate( std::vector<int>& nums ){
        std::unordered_set<int> sett {};
        for( int i : nums ){
            if( sett.count(i)>0 ){ return true; }
            sett.insert(i);
        }
        return false;
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 217 :end ~~~~\n" );
}
}//~
