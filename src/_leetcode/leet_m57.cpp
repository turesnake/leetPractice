/*
 * ====================== leet_m57.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题57. 和为s的两个数字
 */
#include "innLeet.h"


namespace leet_m57 {//~



std::vector<int> twoSum( std::vector<int>& nums, int target ){

    if( nums.size()<2 ){ return {}; }
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while( left < right ){
        int lv = nums.at(left);
        int rv = nums.at(right);
        int sum = lv + rv;
        if( sum == target ){ return { lv, rv }; } // 目标对
        (sum > target) ? right-- : left++;
    }
    return {};
}




//=========================================================//
void main_(){

    std::vector<int> v { 10,26,30,31,47,60 };

    auto ret = twoSum( v, 40 );

    cout << "ret: ";
    for( int i : ret ){
        cout << i << ", ";
    }
    cout << endl;
    


    debug::log( "\n~~~~ leet: m57 :end ~~~~\n" );
}
}//~
