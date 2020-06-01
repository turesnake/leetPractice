/*
 * ====================== leet_m39.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题39. 数组中出现次数超过一半的数字
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m39 {//~



int majorityElement( std::vector<int>& nums ){

    int count {0};
    int candidate {};
    for( int i : nums ){
        if( count==0 ){ candidate = i; }
        (candidate==i) ?
            count++ :
            count--;
    }
    //---//
    int N = static_cast<int>(nums.size());
    count = 0;
    for( int i : nums ){
        if( candidate==i ){ count++; }
    }
    assert( count > N/2 );
    return candidate;
}



//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: m39 :end ~~~~\n" );
}
}//~
