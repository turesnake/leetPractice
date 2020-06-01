/*
 * ====================== leet_m17_10.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.10. 主要元素
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m17_10 {//~



int majorityElement( std::vector<int>& nums ){

    if(nums.empty()){ return -1; }
    int count {0};
    int candidate {};
    for( int i : nums ){
        if( count==0 ){ candidate = i; }
        (candidate==i) ?
            count++ :
            count--;
    }
    //--check--//
    int N = static_cast<int>(nums.size());
    count = 0;
    for( int i : nums ){
        if( candidate==i ){ count++; }
    }
    return (count>N/2 ) ? candidate : -1;
}



//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: m17_10 :end ~~~~\n" );
}
}//~
