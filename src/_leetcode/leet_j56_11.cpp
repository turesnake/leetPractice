/*
 * ====================== leet_j56_11.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.07
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 56 - II. 数组中数字出现的次数 II
 */
#include "innLeet.h"


namespace leet_j56_11 {//~



//   76%   100%
class S{
public:
    // 1 <= nums.length <= 10000
    // 1 <= nums[i] < 2^31
    int singleNumber( std::vector<int>& nums ){

        int64_t totalSum = 0;// 全体元素和
        int64_t elemSum = 0;// 每个非重复值 的和
        std::unordered_set<int> uset {};

        for( int i:nums ){
            totalSum += i;
            if( uset.count(i)==0 ){
                uset.insert(i);
                elemSum += i;
            }
        }
        return static_cast<int>( (elemSum*3-totalSum)/2 );

    }
};




//=========================================================//
void main_(){

    
    


    debug::log( "\n~~~~ leet: j56_11 :end ~~~~\n" );
}
}//~
