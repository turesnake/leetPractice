/*
 * ====================== leet_628.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 628. 三个数的最大乘积
 */
#include "innLeet.h"


namespace leet_628 {//~



// 思路就是，只有两种搭配法：
// -1- 排序后，最大的3个值， 
// -2- 排序后，最大值 和两个 最小值

//   60%   8%
class S{
public:
    // 给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]
    // 输入的数组中任意三个数的乘积不会超出32位有符号整数的范围
    int maximumProduct( std::vector<int>& nums ){

        std::sort( nums.begin(), nums.end() );
        int N = static_cast<int>(nums.size());

        int mmax = nums[N-1] * nums[N-2] * nums[N-3];// 默认选项

        // 一正两负
        if( nums[N-1]>0 && nums[1]<0 ){// 最大值为正，负数个数大于2
            mmax = std::max( mmax, nums[N-1]*nums[0]*nums[1] );
        }

        return mmax;


    }
};




//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 628 :end ~~~~\n" );
}
}//~
