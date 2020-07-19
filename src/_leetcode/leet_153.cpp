/*
 * ====================== leet_153.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 153. 寻找旋转排序数组中的最小值
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_153 {//~


// 与 154 题相比，本题唯一的简化就是，不存在重复元素


//   100%   5%
class S{
public:
    // 元素无重复 
    int findMin( std::vector<int>& nums) {

        int N = static_cast<int>(nums.size());
        int l=0;
        int r=N-1;
        while( l<r ){
            int mid = l+(r-l)/2;//mid-left
            if( nums[mid] > nums[r] ){
                l = mid+1;// 坚决剔除
            }else{// <
                r = mid;  // 保留到下一回合
            }
        }
        return nums[l];

    }
};



//=========================================================//
void main_(){



    debug::log( "\n~~~~ leet: 153 :end ~~~~\n" );
}
}//~
