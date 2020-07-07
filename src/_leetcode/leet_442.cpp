/*
 * ====================== leet_442.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.07
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 442. 数组中重复的数据
 */
#include "innLeet.h"


namespace leet_442 {//~

// 基于下标的 元素交换法
// 全部交换完毕后，最后 与下标值 不一致的元素，就是 要找的 重复值


//   85%   33%
class S{
public:
    // 1<= [i] <= n
    // 共 n 个元素 
    std::vector<int> findDuplicates( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());
        for( int i=1; i<=N; i++ ){
            while( nums[i-1] != i ){
                int tgtI = nums[i-1];
                if( nums[tgtI-1] == tgtI ){ break; }
                std::swap( nums[i-1], nums[tgtI-1] );                
            }
        }
        std::vector<int> outs {};
        for( int i=1; i<=N; i++ ){
            if( nums[i-1] != i ){
                outs.push_back( nums[i-1] );
            }
        }
        return outs;

    }
};


//=========================================================//
void main_(){



    debug::log( "\n~~~~ leet: 442 :end ~~~~\n" );
}
}//~
