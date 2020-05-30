/*
 * ====================== leet_414.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 414. 第三大的数
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_414 {//~


// 无数所有重复元素 
int thirdMax( std::vector<int> nums ){

    std::set<int> sett (nums.begin(), nums.end());
    auto it = sett.rbegin();
    if( sett.size()>=3 ){ 
        it++;
        it++;
    }
    return *it;
}




//=========================================================//
void main_(){

    cout << thirdMax({ 3,3,3 }) << endl;

    
    
    

    debug::log( "\n~~~~ leet: 414 :end ~~~~\n" );
}
}//~
