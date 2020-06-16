/*
 * ===================== leet_1480.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1480. 一维数组的动态和
 */
#include "innLeet.h"


namespace leet_1480 {//~


// 其实就是 前缀和  100%  100%
class S{
public:
    // 1 <= nums.len <= 1000
    // -10^6 <= nums[i] <= 10^6
    std::vector<int> runningSum( std::vector<int>& nums){

        size_t N = nums.size();
        for( size_t i=1; i<N; i++ ){//[i-1],[i]
            nums.at(i) += nums.at(i-1);
        }
        return nums;

    }
};




//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 1480 :end ~~~~\n" );
}
}//~
