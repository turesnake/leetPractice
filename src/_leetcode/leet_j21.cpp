/*
 * ====================== leet_j21.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_j21 {//~



//   99%  100%
class S{
public:
    // 1 <= nums.length <= 50000
    // 1 <= nums[i] <= 10000
    std::vector<int> exchange( std::vector<int>& nums ){

        if( nums.empty() ){ return {}; }

        int N = static_cast<int>(nums.size());

        int l=0;
        int r=N-1;

        while( l<r ){
            for(; l<r && (nums[l]&1)==1; l++ ){}
            for(; l<r && (nums[r]&1)==0; r-- ){}
            if( l<r ){
                std::swap( nums[l], nums[r] );
            }
        }
        return nums;


    }
};



//=========================================================//
void main_(){



    debug::log( "\n~~~~ leet: j21 :end ~~~~\n" );
}
}//~
