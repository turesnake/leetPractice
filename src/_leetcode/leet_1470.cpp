/*
 * ====================== leet_1470.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1470. 重新排列数组
 */
#include "innLeet.h"


namespace leet_1470 {//~



//  94%   100%
class S{
public:
    // 1 <= n <= 500
    // nums.length == 2n
    // 1 <= nums[i] <= 10^3
    std::vector<int> shuffle( std::vector<int>& nums, int n ){

        std::vector<int> out {};
        for( int a=0,b=n; a<n; a++,b++ ){
            out.push_back( nums[a] );
            out.push_back( nums[b] );
        }
        return out;

    }
};




//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 1470 :end ~~~~\n" );
}
}//~
