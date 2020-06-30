/*
 * ====================== leet_740.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 740. 删除与获得点数
 */
#include "innLeet.h"


namespace leet_740 {//~


// dp，思路上类似 “打家劫舍” 题
//   47%   100%
class S{

struct Elem{
    int val {};
    int num {};
};

public:
    // nums 的长度最大为 20000
    // 每个整数 nums[i] 的大小都在 [1, 10000] 范围内
    int deleteAndEarn( std::vector<int>& nums ){

        if( nums.empty() ){ return 0; }

        // 整理原始数据
        std::sort( nums.begin(), nums.end() );
        std::vector<Elem> elems {};
        int tval = nums[0];
        int tnum = 1;
        for( size_t i=1; i<nums.size(); i++ ){
            if( nums[i] == tval ){
                tnum++;
            }else{
                elems.push_back(Elem{ tval, tnum });
                tval = nums[i];
                tnum = 1;
            }
        }
        elems.push_back(Elem{ tval, tnum });

        // 正式 dp
        int N = static_cast<int>(elems.size());
        std::vector<std::vector<int>> dp (N, std::vector<int>(2,0));

        dp[0][1] = elems[0].val * elems[0].num;
        for( int i=1; i<N; i++ ){// [i-1], [i]
            // [0]
            dp[i][0] = std::max( dp[i-1][0], dp[i-1][1] );
            // [1]
            int val = elems[i].val*elems[i].num;
            if( elems[i].val-elems[i-1].val == 1 ){// 相邻
                dp[i][1] = dp[i-1][0] + val;
            }else{// 不相邻
                dp[i][1] = std::max(dp[i-1][0], dp[i-1][1]) + val;
            }
        }
        return std::max( dp[N-1][0], dp[N-1][1] );


    }
};




//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 740 :end ~~~~\n" );
}
}//~
