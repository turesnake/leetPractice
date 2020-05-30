/*
 * ====================== leet_1365.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1365. 有多少小于当前数字的数字
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1365 {//~


// 2 <= nums.length <= 500
// 0 <= nums[i] <= 100
std::vector<int> smallerNumbersThanCurrent( std::vector<int>& nums ){

    int N = static_cast<int>(nums.size());
    std::vector<int> v (101,0);//[0,100]
    for( int i : nums ){
        v.at(i)++;
    }

    int sum = 0;
    for( auto &e : v ){
        int tmp = sum;
        sum += e;
        e = tmp;
    }

    std::vector<int> outs (N,0);
    for( int i=0; i<N; i++ ){
        outs.at(i) = v.at(nums.at(i));
    }
    return outs;
}


//=========================================================//
void main_(){

    



    debug::log( "\n~~~~ leet: 1365 :end ~~~~\n" );
}
}//~
