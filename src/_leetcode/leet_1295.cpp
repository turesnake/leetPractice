/*
 * ====================== leet_1295.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1295. 统计位数为偶数的数字
 */
#include "innLeet.h"


namespace leet_1295 {//~


// int 存在上限：10^5
// 直接枚举 区间


//   93%   8%
class S{
public:
    // 1 <= nums.length <= 500
    // 1 <= nums[i] <= 10^5
    int findNumbers( std::vector<int>& nums ){

        int sum = 0;
        for( int i : nums ){
            if( ( i>=10 && i<=99 ) ||
                ( i>=1000 && i<=9999 ) ||
                ( i==100000 )){ 
                sum++; 
            }
        }
        return sum;

    }
};



//  利用语言 现成函数 log10()

//   93%   8%
class S2{
public:
    // 1 <= nums.length <= 500
    // 1 <= nums[i] <= 10^5
    int findNumbers( std::vector<int>& nums ){

        int sum = 0;
        for( int i : nums ){
            int len = static_cast<int>(log10(i))+1;
            if( (len&1)==0){ sum++; }
        }
        return sum;

    }
};



//=========================================================//
void main_(){

    auto v =  static_cast<int>(log10(12345))+1;
    


    debug::log( "\n~~~~ leet: 1295 :end ~~~~\n" );
}
}//~
