/*
 * ====================== leet_154.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 154. 寻找旋转排序数组中的最小值 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_154 {//~


// 与 j11 题相同 


class S{
public:
    // 元素是存在重复的 
    int minArray( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());
        for(; N>1 && nums[0]==nums[N-1]; N-- ){}// 剔除所有与 n[0] 同值的 尾元素

        int l=0;
        int r=N-1;
        while( l<r ){
            int mid = l+(r-l)/2;//mid-left
            if( nums[mid] > nums[r] ){
                l = mid+1;// 坚决剔除
            }else{// <=
                r = mid;  // 保留到下一回合
            }
        }
        return nums[l];

    }
};



//=========================================================//
void main_(){



    debug::log( "\n~~~~ leet: 154 :end ~~~~\n" );
}
}//~
