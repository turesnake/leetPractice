/*
 * ====================== leet_1121.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1121. 将数组分成几个递增序列
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_1121 {//~


// 官方
// 寻找原始数组中，出现次数最多的元素，计其出现次数为 t
// 数组 至少要被拆分为 t 个 子系列
// 按照官方解释，
// 只要满足，t*k <= nums.size()
// 就说明 可以被拆分
// ...


// 其实并不算理解...


//  83%  100%
class S{
public:
    // 1 <= nums.length <= 10^5
    // 1 <= K <= nums.length
    // 1 <= nums[i] <= 10^5
    bool canDivideIntoSubsequences( std::vector<int>& nums, int K ){

        int N = static_cast<int>(nums.size());
        int pre = 0;
        int cnt = 0;
        int maxT = 0;

        for( int i=0; i<N; i++ ){
            if( nums[i]==pre ){
                cnt++;
            }else{
                maxT = std::max( maxT, cnt );
                pre = nums[i];
                cnt = 1;
            }
        }
        maxT = std::max( maxT, cnt );
        //---//
        return maxT*K <= N;

    }
};


//=========================================================//
void main_(){





    

    debug::log( "\n~~~~ leet: 1121 :end ~~~~\n" );
}
}//~
